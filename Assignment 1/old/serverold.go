package main

import (
	"bufio"
	"fmt"
	"net"
	"strings"
	"sync"
)

type Task struct {
	ClientID  string
	Operation string
	MatrixA   string
	MatrixB   string
}

type Worker struct {
	Conn     net.Conn
	Workload int
}

var (
	workers       []*Worker
	clientMap     = make(map[string]net.Conn)
	clientMapLock sync.Mutex
	taskQueue     []Task
	workerLock    sync.Mutex
)

func main() {
	listener, err := net.Listen("tcp", ":12345")
	if err != nil {
		fmt.Println("Error starting server:", err)
		return
	}
	defer listener.Close()

	fmt.Println("Server is running on port 12345...")

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Error accepting connection:", err)
			continue
		}

		go handleConnection(conn)
	}
}

func handleConnection(conn net.Conn) {
	defer conn.Close()
	reader := bufio.NewReader(conn)

	for {
		message, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("Client disconnected.")
			return
		}

		message = strings.TrimSpace(message)
		parts := strings.Split(message, "|")

		if len(parts) == 0 {
			continue
		}

		switch parts[0] {
		case "WORKER":
			worker := &Worker{Conn: conn, Workload: 0}
			workers = append(workers, worker)
			fmt.Printf("New worker added! Total workers: %d\n", len(workers))

		case "CLIENT":
			if len(parts) < 5 {
				conn.Write([]byte("Invalid task format\n"))
				continue
			}
			clientID := parts[1]
			task := Task{
				ClientID:  clientID,
				Operation: parts[2],
				MatrixA:   parts[3],
				MatrixB:   parts[4],
			}

			clientMapLock.Lock()
			clientMap[clientID] = conn
			clientMapLock.Unlock()

			fmt.Printf("Task received from client %s: %s|%s|%s\n", clientID, task.Operation, task.MatrixA, task.MatrixB)

			workerLock.Lock()
			taskQueue = append(taskQueue, task)
			workerLock.Unlock()

			go assignTasks()

		case "RESULT":
			if len(parts) < 3 {
				fmt.Println("Invalid result format received:", message)
				continue
			}
			clientID := parts[1]
			result := strings.Join(parts[2:], "|")

			clientMapLock.Lock()
			client, exists := clientMap[clientID]
			clientMapLock.Unlock()

			if exists {
				client.Write([]byte(result + "\n"))
				fmt.Printf("Result sent to client %s: %s\n", clientID, result)
			} else {
				fmt.Println("Client not found for result:", result)
			}
		}
	}
}

func assignTasks() {
	workerLock.Lock()
	defer workerLock.Unlock()

	for len(taskQueue) > 0 && len(workers) > 0 {
		// Find the least busy worker
		var leastBusyWorker *Worker
		for _, worker := range workers {
			if leastBusyWorker == nil || worker.Workload < leastBusyWorker.Workload {
				leastBusyWorker = worker
			}
		}

		// Assign the task to the least busy worker
		task := taskQueue[0]
		taskQueue = taskQueue[1:]

		leastBusyWorker.Workload++
		fmt.Printf("Task assigned to worker: %s|%s|%s\n", task.Operation, task.MatrixA, task.MatrixB)

		// Send task to worker
		leastBusyWorker.Conn.Write([]byte("TASK|" + task.ClientID + "|" + task.Operation + "|" + task.MatrixA + "|" + task.MatrixB + "\n"))

		// Decrease workload after task is processed
		go func(worker *Worker) {
			worker.Workload--
		}(leastBusyWorker)
	}
}
