package main

import (
	"bufio"
	"fmt"
	"net"
	"strings"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:12345")
	if err != nil {
		fmt.Println("Error connecting to server:", err)
		return
	}
	defer conn.Close()

	_, err = conn.Write([]byte("worker\n"))
	if err != nil {
		fmt.Println("Error registering as worker:", err)
		return
	}

	fmt.Println("Worker registered. Waiting for tasks...")

	reader := bufio.NewReader(conn)
	for {
		task, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("Error reading task:", err)
			break // Worker exits if it can't read
		}

		task = strings.TrimSpace(task)
		fmt.Println("Received task:", task)

		// **Simple processing (Just echoing back for now)**
		result := "Processed: " + task

		_, err = conn.Write([]byte(result + "\n"))
		if err != nil {
			fmt.Println("Error sending result:", err)
			break
		}
	}
}
