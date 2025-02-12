package main

import (
	"bufio"
	"fmt"
	"net"
	"strings"
	"sync"
)

var workers []net.Conn
var workerLock sync.Mutex

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
	message, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading from connection:", err)
		return
	}

	message = strings.TrimSpace(message)
	fmt.Println("Received:", message)

	if message == "worker" {
		workerLock.Lock()
		workers = append(workers, conn)
		workerLock.Unlock()
		fmt.Println("New worker added! Total workers:", len(workers))

		// Keep worker alive
		for {
			task, err := reader.ReadString('\n')
			if err != nil {
				fmt.Println("Worker disconnected:", err)
				removeWorker(conn)
				return
			}

			task = strings.TrimSpace(task)
			fmt.Println("Task assigned to worker:", task)

			_, err = conn.Write([]byte(task + "\n")) // Send task to worker
			if err != nil {
				fmt.Println("Error sending task to worker:", err)
				removeWorker(conn)
				return
			}
		}
	}

	// **Handle client request**
	workerLock.Lock()
	if len(workers) > 0 {
		worker := workers[0]
		workerLock.Unlock()

		_, err := worker.Write([]byte(message + "\n"))
		if err != nil {
			fmt.Println("Error sending task to worker:", err)
			removeWorker(worker)
			return
		}

		workerReader := bufio.NewReader(worker)
		result, err := workerReader.ReadString('\n')
		if err != nil {
			fmt.Println("Error reading from worker:", err)
			removeWorker(worker)
			return
		}

		result = strings.TrimSpace(result)
		fmt.Println("Result from worker:", result)

		_, err = conn.Write([]byte(result + "\n"))
		if err != nil {
			fmt.Println("Error sending response to client:", err)
		}

	} else {
		workerLock.Unlock()
		conn.Write([]byte("No workers available\n"))
	}
}

func removeWorker(conn net.Conn) {
	workerLock.Lock()
	defer workerLock.Unlock()
	for i, w := range workers {
		if w == conn {
			workers = append(workers[:i], workers[i+1:]...)
			fmt.Println("Worker removed! Remaining workers:", len(workers))
			return
		}
	}
}
