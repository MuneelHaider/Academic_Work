package main

import (
	"bufio"
	"fmt"
	"net"
	"strings"
	"sync"
)

var (
	workers       []net.Conn
	clientMap     = make(map[string]net.Conn) // Store client connections
	clientMapLock sync.Mutex                  // Synchronization lock for map access
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
	reader := bufio.NewReader(conn)

	for {
		message, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("Client disconnected.")
			conn.Close()
			return
		}

		message = strings.TrimSpace(message)
		parts := strings.Split(message, "|")

		if len(parts) == 0 {
			continue
		}

		switch parts[0] {
		case "WORKER":
			workers = append(workers, conn)
			fmt.Printf("New worker added! Total workers: %d\n", len(workers))

		case "CLIENT":
			if len(parts) < 3 {
				conn.Write([]byte("Invalid task format\n"))
				continue
			}
			clientID := parts[1]
			task := strings.Join(parts[2:], "|") // Reconstruct the task

			// Store client connection
			clientMapLock.Lock()
			clientMap[clientID] = conn
			clientMapLock.Unlock()

			if len(workers) > 0 {
				worker := workers[0]
				workers = workers[1:] // Round-robin worker selection

				// Send task to worker with client ID
				worker.Write([]byte("TASK|" + clientID + "|" + task + "\n"))
				workers = append(workers, worker) // Worker goes back to the pool
				fmt.Println("Task assigned to worker:", task)
			} else {
				conn.Write([]byte("No available workers\n"))
			}

		case "RESULT":
			if len(parts) < 3 {
				fmt.Println("Invalid result format received:", message)
				continue
			}
			clientID := parts[1]
			result := strings.Join(parts[2:], "|") // Preserve full result

			clientMapLock.Lock()
			client, exists := clientMap[clientID]
			clientMapLock.Unlock()

			if exists {
				client.Write([]byte("RESULT|" + result + "\n"))
				fmt.Println("Result sent to client:", result)
			} else {
				fmt.Println("Client not found for result:", result)
			}
		}
	}
}
