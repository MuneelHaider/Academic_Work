package main

import (
	"bufio"
	"fmt"
	"net"
	"strconv"
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
			break
		}

		task = strings.TrimSpace(task)
		fmt.Println("Received task:", task)

		result := processTask(task)
		_, err = conn.Write([]byte(result + "\n"))
		if err != nil {
			fmt.Println("Error sending result:", err)
			break
		}
	}
}

func processTask(task string) string {
	parts := strings.Split(task, "|")
	if len(parts) < 1 {
		return "Invalid task format. Use: OPERATION|matrix1|matrix2"
	}

	operation := strings.ToUpper(parts[0])

	switch operation {
	case "ADD":
		if len(parts) != 3 {
			return "ADD requires two matrices"
		}
		m1, err1 := parseMatrix(parts[1])
		m2, err2 := parseMatrix(parts[2])
		if err1 != nil || err2 != nil {
			return "Invalid matrix format"
		}
		result, err := addMatrices(m1, m2)
		if err != nil {
			return err.Error()
		}
		return matrixToString(result)

	case "MULTIPLY":
		if len(parts) != 3 {
			return "MULTIPLY requires two matrices"
		}
		m1, err1 := parseMatrix(parts[1])
		m2, err2 := parseMatrix(parts[2])
		if err1 != nil || err2 != nil {
			return "Invalid matrix format"
		}
		result, err := multiplyMatrices(m1, m2)
		if err != nil {
			return err.Error()
		}
		return matrixToString(result)

	case "TRANSPOSE":
		if len(parts) != 2 {
			return "TRANSPOSE requires one matrix"
		}
		m, err := parseMatrix(parts[1])
		if err != nil {
			return "Invalid matrix format"
		}
		return matrixToString(transposeMatrix(m))

	default:
		return "Unsupported operation"
	}
}

// Helper functions for matrix operations
func parseMatrix(s string) ([][]int, error) {
	rows := strings.Split(s, ";")
	matrix := make([][]int, len(rows))
	for i, row := range rows {
		cols := strings.Fields(row)
		matrixRow := make([]int, len(cols))
		for j, col := range cols {
			val, err := strconv.Atoi(col)
			if err != nil {
				return nil, err
			}
			matrixRow[j] = val
		}
		matrix[i] = matrixRow
	}
	return matrix, nil
}

func matrixToString(m [][]int) string {
	var sb strings.Builder
	for i, row := range m {
		for j, val := range row {
			if j > 0 {
				sb.WriteString(" ")
			}
			sb.WriteString(strconv.Itoa(val))
		}
		if i < len(m)-1 {
			sb.WriteString(";")
		}
	}
	return sb.String()
}

func addMatrices(a, b [][]int) ([][]int, error) {
	if len(a) != len(b) || len(a[0]) != len(b[0]) {
		return nil, fmt.Errorf("matrix dimensions mismatch")
	}

	result := make([][]int, len(a))
	for i := range a {
		result[i] = make([]int, len(a[i]))
		for j := range a[i] {
			result[i][j] = a[i][j] + b[i][j]
		}
	}
	return result, nil
}

func multiplyMatrices(a, b [][]int) ([][]int, error) {
	if len(a[0]) != len(b) {
		return nil, fmt.Errorf("incompatible dimensions for multiplication")
	}

	result := make([][]int, len(a))
	for i := range result {
		result[i] = make([]int, len(b[0]))
	}

	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b[0]); j++ {
			sum := 0
			for k := 0; k < len(b); k++ {
				sum += a[i][k] * b[k][j]
			}
			result[i][j] = sum
		}
	}
	return result, nil
}

func transposeMatrix(m [][]int) [][]int {
	rows := len(m)
	cols := len(m[0])
	result := make([][]int, cols)
	for i := range result {
		result[i] = make([]int, rows)
		for j := range result[i] {
			result[i][j] = m[j][i]
		}
	}
	return result
}
