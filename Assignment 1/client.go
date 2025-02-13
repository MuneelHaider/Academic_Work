package main

/*
Blockchain Assignment 1 - Section B

Muneel Haider		21i-0640
Abdullah Zahoor		21i-2481
*/

import (
	"bufio"
	"crypto/tls"
	"fmt"
	"net/rpc"
	"os"
	"strings"
	"time"
)

type TaskRequest struct {
	ClientID  string
	Operation string
	MatrixA   string
	MatrixB   string
}

func main() {
	tlsConfig := &tls.Config{InsecureSkipVerify: true}

	fmt.Println("[CLIENT] Connecting to server on port 6000...")
	conn, err := tls.Dial("tcp", "localhost:6000", tlsConfig)
	if err != nil {
		fmt.Println("[CLIENT] Error connecting to server:", err)
		return
	}
	defer conn.Close()
	fmt.Println("[CLIENT] Connection established.")

	client := rpc.NewClient(conn)
	defer client.Close()

	clientID := fmt.Sprintf("%d", time.Now().UnixNano())

	reader := bufio.NewReader(os.Stdin)

	fmt.Print("[CLIENT] Enter operation (ADD, MUL, TRANSPOSE): ")
	operation, _ := reader.ReadString('\n')
	operation = strings.TrimSpace(operation)

	fmt.Print("[CLIENT] Enter first matrix (example 1 2;3 4): ")
	matrixA, _ := reader.ReadString('\n')
	matrixA = strings.TrimSpace(matrixA)

	var matrixB string
	if operation != "TRANSPOSE" {
		fmt.Print("[CLIENT] Enter second matrix (example 5 6;7 8): ")
		matrixB, _ = reader.ReadString('\n')
		matrixB = strings.TrimSpace(matrixB)
	}

	request := TaskRequest{ClientID: clientID, Operation: operation, MatrixA: matrixA, MatrixB: matrixB}
	var response string

	fmt.Println("[CLIENT] Sending task to server...")
	err = client.Call("Server.SubmitTask", request, &response)
	if err != nil {
		fmt.Println("[CLIENT] Error sending task:", err)
		return
	}

	fmt.Println("[CLIENT] Server response:", response)

	fmt.Println("[CLIENT] Waiting for result from server...")
	err = client.Call("Server.GetResult", clientID, &response)
	if err != nil {
		fmt.Println("[CLIENT] Error getting result:", err)
		return
	}

	fmt.Println("[CLIENT] Final Result:\n", response)
}
