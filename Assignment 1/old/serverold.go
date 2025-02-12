package main

import (
	"bufio"
	"fmt"
	"net"
	"strings"
	"sync"
	"time"
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
	workers    []*Worker
	clientMap  sync.Map // Use sync.Map to store client connections
	taskQueue  []Task
	workerLock sync.Mutex
)

func main() {
	listener, err := net.Listen("tcp", ":12345")
	if err != nil {
		fmt.Println("Error starting server:", err)
		return
	}
	defer listener.Close()

	fmt.Println("Server is running on port 12345...")

	// Handle incoming connections
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
			// Register a new worker
			worker := &Worker{Conn: conn, Workload: 0}
			workers = append(workers, worker)
			fmt.Printf("New worker added! Total workers: %d\n", len(workers))

		case "CLIENT":
			// Register a new client
			if len(parts) < 2 {
				fmt.Println("Invalid client format received:", message)
				continue
			}
			clientID := parts[1]
			clientMap.Store(clientID, conn)
			fmt.Printf("Client %s connected.\n", clientID)

		case "TASK":
			// Receive a task from a client
			if len(parts) < 5 {
				fmt.Println("Invalid task format received:", message)
				continue
			}
			clientID := parts[1]
			operation := parts[2]
			matrixA := parts[3]
			matrixB := parts[4]

			// Create a new task
			task := Task{
				ClientID:  clientID,
				Operation: operation,
				MatrixA:   matrixA,
				MatrixB:   matrixB,
			}

			// Add the task to the queue
			workerLock.Lock()
			taskQueue = append(taskQueue, task)
			workerLock.Unlock()

			fmt.Printf("Task received from client %s: %s|%s|%s\n", clientID, operation, matrixA, matrixB)

			// Assign tasks to workers
			go assignTasks()

		case "RESULT":
			// Receive a result from a worker
			if len(parts) < 3 {
				fmt.Println("Invalid result format received:", message)
				continue
			}
			clientID := parts[1]
			result := strings.Join(parts[2:], "|")

			// Send the result back to the client
			client, exists := clientMap.Load(clientID)
			if exists {
				_, err := client.(net.Conn).Write([]byte("RESULT|" + result + "\n"))
				if err != nil {
					fmt.Println("Error sending result to client:", err)
				} else {
					fmt.Printf("Result sent to client %s: %s\n", clientID, result)
				}
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
		_, err := leastBusyWorker.Conn.Write([]byte("TASK|" + task.ClientID + "|" + task.Operation + "|" + task.MatrixA + "|" + task.MatrixB + "\n"))
		if err != nil {
			fmt.Println("Error sending task to worker:", err)
			removeWorker(leastBusyWorker)
			continue
		}

		// Decrease workload after task is processed
		go func(worker *Worker) {
			time.Sleep(1 * time.Second) // Simulate task processing time
			worker.Workload--
		}(leastBusyWorker)
	}
}

func removeWorker(worker *Worker) {
	workerLock.Lock()
	defer workerLock.Unlock()

	for i, w := range workers {
		if w == worker {
			workers = append(workers[:i], workers[i+1:]...)
			fmt.Println("Worker removed! Remaining workers:", len(workers))
			return
		}
	}
}
