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

	task := "10 + 5\n"
	_, err = conn.Write([]byte(task))
	if err != nil {
		fmt.Println("Error sending task:", err)
		return
	}

	reader := bufio.NewReader(conn)
	response, err := reader.ReadString('\n') // **Ensure full response is read**
	if err != nil {
		fmt.Println("Error reading response:", err)
		return
	}

	fmt.Println("Server response:", strings.TrimSpace(response))
}
