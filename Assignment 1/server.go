package main

import (
	"bufio"
	"crypto/tls"
	"fmt"
	"net"
	"net/rpc"
	"strings"
	"sync"
)

type Task struct {
	ClientID  string
	Operation string
	MatrixA   string
	MatrixB   string
}

type Server struct {
	Tasks     []Task
	TaskQueue chan Task
	Workers   []net.Conn
	Results   map[string]string
	mu        sync.Mutex
}

// Submit task via RPC (Client -> Server)
func (s *Server) SubmitTask(task Task, reply *string) error {
	fmt.Printf("[SERVER] 📥 Received task from Client %s: %s\n", task.ClientID, task.Operation)
	s.mu.Lock()
	s.TaskQueue <- task
	s.mu.Unlock()
	*reply = "Task received and queued"
	return nil
}

// Retrieve result via RPC (Client -> Server)
func (s *Server) GetResult(clientID string, reply *string) error {
	fmt.Printf("[SERVER] 🕒 Client %s waiting for result...\n", clientID)
	for {
		s.mu.Lock()
		if result, exists := s.Results[clientID]; exists {
			fmt.Printf("[SERVER] ✅ Result sent to Client %s: %s\n", clientID, result)
			*reply = result
			delete(s.Results, clientID)
			s.mu.Unlock()
			return nil
		}
		s.mu.Unlock()
	}
}

// Accept worker connections via TCP
func (s *Server) HandleWorkerConnections(listener net.Listener) {
	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("[SERVER] ❌ Worker connection error:", err)
			continue
		}

		fmt.Println("[SERVER] ✅ New worker connected.")
		s.mu.Lock()
		s.Workers = append(s.Workers, conn)
		s.mu.Unlock()

		go s.AssignTasksToWorker(conn)
	}
}

// Assign tasks to workers via TCP
func (s *Server) AssignTasksToWorker(worker net.Conn) {
	reader := bufio.NewReader(worker)

	for task := range s.TaskQueue {
		taskString := fmt.Sprintf("TASK|%s|%s|%s|%s\n", task.ClientID, task.Operation, task.MatrixA, task.MatrixB)
		worker.Write([]byte(taskString))

		result, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("[SERVER] ❌ Worker disconnected, reassigning task.")
			s.mu.Lock()
			s.TaskQueue <- task
			s.mu.Unlock()
			return
		}

		parts := strings.Split(strings.TrimSpace(result), "|")
		if len(parts) < 3 || parts[0] != "RESULT" {
			fmt.Println("[SERVER] ❌ Invalid result format from worker:", result)
			continue
		}

		clientID := parts[1]
		s.mu.Lock()
		s.Results[clientID] = parts[2]
		s.mu.Unlock()
		fmt.Printf("[SERVER] ✅ Result stored for Client %s: %s\n", clientID, parts[2])
	}
}

func main() {
	server := &Server{
		TaskQueue: make(chan Task, 10),
		Results:   make(map[string]string),
	}

	rpc.Register(server)

	// Start RPC server for clients
	go func() {
		cert, err := tls.LoadX509KeyPair("cert.pem", "key.pem")
		if err != nil {
			fmt.Println("[SERVER] ❌ Error loading TLS certificates:", err)
			return
		}
		config := &tls.Config{Certificates: []tls.Certificate{cert}}
		listener, err := tls.Listen("tcp", ":6000", config)
		if err != nil {
			fmt.Println("[SERVER] ❌ Server error:", err)
			return
		}
		defer listener.Close()

		fmt.Println("[SERVER] ✅ RPC Server started on port 6000...")
		for {
			conn, err := listener.Accept()
			if err != nil {
				fmt.Println("[SERVER] ❌ RPC Connection error:", err)
				continue
			}
			go rpc.ServeConn(conn)
		}
	}()

	// Start TCP server for workers
	workerListener, err := net.Listen("tcp", ":6001")
	if err != nil {
		fmt.Println("[SERVER] ❌ Error starting Worker Listener:", err)
		return
	}
	fmt.Println("[SERVER] ✅ Worker Listener started on port 6001...")
	server.HandleWorkerConnections(workerListener)
}
