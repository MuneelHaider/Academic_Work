package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:12345")
	if err != nil {
		fmt.Println("Error connecting to server:", err)
		return
	}
	defer conn.Close()

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter task (e.g., ADD|1 2;3 4|5 6;7 8): ")
	task, _ := reader.ReadString('\n')
	task = strings.TrimSpace(task)

	_, err = conn.Write([]byte(task + "\n"))
	if err != nil {
		fmt.Println("Error sending task:", err)
		return
	}

	serverReader := bufio.NewReader(conn)
	response, err := serverReader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading response:", err)
		return
	}

	fmt.Println("Server response:", strings.TrimSpace(response))
}
