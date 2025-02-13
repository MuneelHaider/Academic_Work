package main

import (
	"bufio"
	"fmt"
	"net"
	"strconv"
	"strings"
)

func main() {
	conn, err := net.Dial("tcp", "localhost:6001")
	if err != nil {
		fmt.Println("[WORKER] Error connecting to server:", err)
		return
	}
	defer conn.Close()

	fmt.Println("[WORKER] Worker connected. Waiting for tasks...")

	reader := bufio.NewReader(conn)

	for {
		task, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("[WORKER] Disconnected. Reconnecting...")
			return
		}

		task = strings.TrimSpace(task)
		parts := strings.Split(task, "|")

		if len(parts) < 5 || parts[0] != "TASK" {
			fmt.Println("[WORKER] Invalid task format received:", task)
			continue
		}

		clientID := parts[1]
		operation := parts[2]
		matrixA := parts[3]
		matrixB := parts[4]

		fmt.Printf("[WORKER] Received task: %s|%s|%s\n", operation, matrixA, matrixB)

		result := processTask(operation, matrixA, matrixB)

		conn.Write([]byte(fmt.Sprintf("RESULT|%s|%s\n", clientID, result)))
		fmt.Printf("[WORKER] Result sent: %s\n", result)
	}
}

func processTask(operation, matrixA, matrixB string) string {
	switch operation {
	case "ADD":
		m1 := parseMatrix(matrixA)
		m2 := parseMatrix(matrixB)
		if m1 == nil || m2 == nil || !isSameSize(m1, m2) {
			return "Invalid matrices"
		}
		return matrixToString(addMatrices(m1, m2))

	case "MUL":
		m1 := parseMatrix(matrixA)
		m2 := parseMatrix(matrixB)
		if m1 == nil || m2 == nil {
			return "Invalid matrices"
		}
		multiplied, err := multiplyMatrices(m1, m2)
		if err != nil {
			return "Multiplication not possible"
		}
		return matrixToString(multiplied)

	case "TRANSPOSE":
		m := parseMatrix(matrixA)
		if m == nil {
			return "Invalid matrix"
		}
		return matrixToString(transposeMatrix(m))

	default:
		return "Invalid operation"
	}
}

func parseMatrix(data string) [][]int {
	rows := strings.Split(data, ";")
	matrix := [][]int{}

	for _, row := range rows {
		nums := strings.Fields(row)
		intRow := []int{}
		for _, num := range nums {
			val, err := strconv.Atoi(num)
			if err != nil {
				return nil
			}
			intRow = append(intRow, val)
		}
		matrix = append(matrix, intRow)
	}

	return matrix
}

func isSameSize(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if len(a[i]) != len(b[i]) {
			return false
		}
	}
	return true
}

func addMatrices(a, b [][]int) [][]int {
	rows := len(a)
	cols := len(a[0])
	result := make([][]int, rows)

	for i := 0; i < rows; i++ {
		result[i] = make([]int, cols)
		for j := 0; j < cols; j++ {
			result[i][j] = a[i][j] + b[i][j]
		}
	}

	return result
}

func multiplyMatrices(a, b [][]int) ([][]int, error) {
	if len(a[0]) != len(b) {
		return nil, fmt.Errorf("invalid dimensions for multiplication")
	}

	rows, cols, common := len(a), len(b[0]), len(a[0])
	result := make([][]int, rows)

	for i := 0; i < rows; i++ {
		result[i] = make([]int, cols)
		for j := 0; j < cols; j++ {
			for k := 0; k < common; k++ {
				result[i][j] += a[i][k] * b[k][j]
			}
		}
	}

	return result, nil
}

func transposeMatrix(matrix [][]int) [][]int {
	rows := len(matrix)
	cols := len(matrix[0])
	transposed := make([][]int, cols)

	for i := 0; i < cols; i++ {
		transposed[i] = make([]int, rows)
		for j := 0; j < rows; j++ {
			transposed[i][j] = matrix[j][i]
		}
	}

	return transposed
}

func matrixToString(matrix [][]int) string {
	var result strings.Builder
	for i, row := range matrix {
		for j, num := range row {
			result.WriteString(fmt.Sprintf("%d", num))
			if j < len(row)-1 {
				result.WriteString(" ")
			}
		}
		if i < len(matrix)-1 {
			result.WriteString(";")
		}
	}
	return result.String()
}
