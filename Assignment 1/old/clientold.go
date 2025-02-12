package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
	"time"
)

func main() {
	conn, err := net.Dial("tcp", "localhost:12345")
	if err != nil {
		fmt.Println("Error connecting to server:", err)
		return
	}
	defer conn.Close()

	// Generate a unique client ID
	clientID := fmt.Sprintf("%d", time.Now().UnixNano())

	// Register the client with the server
	conn.Write([]byte("CLIENT|" + clientID + "\n"))

	// Read task from user input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter task (e.g., ADD|1 2;3 4|5 6;7 8): ")
	task, _ := reader.ReadString('\n')
	task = strings.TrimSpace(task)

	// Send task to the server
	conn.Write([]byte("TASK|" + clientID + "|" + task + "\n"))

	// Receive response
	serverReader := bufio.NewReader(conn)
	response, _ := serverReader.ReadString('\n')
	fmt.Println("Server response:", strings.TrimSpace(response))
}
