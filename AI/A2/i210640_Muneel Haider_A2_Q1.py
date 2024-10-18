import numpy as np
import random

# Muneel Haider i210640
# AI - CS(G)
# Assignment 2 - Question 1

def isValid(board, row, col, num):
    for x in range(9):
   
        if board[row][x] == num or board[x][col] == num:
            return False
   
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
   
    for i in range(3): 
        for j in range(3):
   
            if board[i + start_row][j + start_col] == num:
                return False
   
    return True

def solvePuzzle(board):
    empty = findEmptyIndex(board)
    
    if not empty:
        return True
    
    row, col = empty
    
    for num in orderValues(board, row, col):
    
        if isValid(board, row, col, num):
            board[row][col] = num
    
            if solvePuzzle(board):
                return True
    
            board[row][col] = 0
    
    return False

def findEmptyIndex(board):
    
    for i in range(9):
        for j in range(9):
    
            if board[i][j] == 0:
                return (i, j)
    
    return None

def unassignedVariable(board):
    mrv = 10

    for i in range(len(board)):
        for j in range(len(board[i])):
    
            if board[i][j] == 0:
                num_possible_values = len(getPossibleValues(board, i, j))
    
                if num_possible_values < mrv:
                    mrv = num_possible_values
                    best_i, best_j = i, j
    
    return best_i, best_j

def getPossibleValues(board, row, col):
    possible_values = set(range(1, 10))

    for i in range(9):
        possible_values.discard(board[row][i])
        possible_values.discard(board[i][col])
    
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    
    for i in range(3):
        for j in range(3):
    
            possible_values.discard(board[i + start_row][j + start_col])
    
    return possible_values

def orderValues(board, row, col):
    possible_values = getPossibleValues(board, row, col)
    lcv_dict = {}
    
    for value in possible_values:
        board[row][col] = value
        lcv_count = sum(len(getPossibleValues(board, i, j)) for i in range(9) for j in range(9) if board[i][j] == 0)
        lcv_dict[value] = lcv_count
        board[row][col] = 0
    
    return sorted(lcv_dict, key=lcv_dict.get, reverse=True)

def AC3(board):
    queue = [(i, j, k, l) for i in range(9) for j in range(9) for k in range(9) for l in range(9) if (i != k or j != l) and (i == k or j == l or (i//3 == k//3 and j//3 == l//3))]

    while queue:
        (i, j, k, l) = queue.pop(0)

        if board[i][j] != 0 and board[i][j] == board[k][l]:
            return False

    return True

def generateSudoku():
    board = np.zeros((9, 9), dtype=int)
   
    for i in range(0, 9, 3):
        fillDiagonalMatrix(board, i)
   
    solvePuzzle(board)
    removeValues(board)
   
    return board

def fillDiagonalMatrix(board, index):
    nums = list(range(1, 10))
    random.shuffle(nums)
  
    for i in range(3):
        for j in range(3):
  
            board[index+i][index+j] = nums.pop()

def removeValues(board, level=3):
    rounds = level * 9
   
    while rounds > 0:
        i = random.randint(0, 8)
        j = random.randint(0, 8)
   
        if board[i][j] != 0:
            board[i][j] = 0
            rounds -= 1

def SolveAllSolutions(board, solutions):
    
    empty = findEmptyIndex(board)
    
    if not empty:
        # Found a solution
        solutions.append(np.copy(board))  
    
        # Looks for more solutions
        return False  
    
    row, col = empty
    
    for num in orderValues(board, row, col):
    
        if isValid(board, row, col, num):
            board[row][col] = num
    
            if SolveAllSolutions(board, solutions):
                return True
    
            board[row][col] = 0
    
    return False

def generateSudokuPuzzle():
    board = np.zeros((9, 9), dtype=int)
 
    for i in range(0, 9, 3):
        fillDiagonalMatrix(board, i)
 
    solvePuzzle(board)
    return board

def removeValuesMultipleSolutions(board, level=3):
    rounds = level * 9

    while rounds > 0:
        i, j = random.randint(0, 8), random.randint(0, 8)

        if board[i][j] != 0:
            board[i][j] = 0
            rounds -= 1



sudokuBoard = generateSudokuPuzzle()
removeValuesMultipleSolutions(sudokuBoard, level=3)


solutions = []
SolveAllSolutions(sudokuBoard, solutions)
print()

if not solutions:
    print("No solution found.")

elif len(solutions) > 1:
    print("Multiple solutions found:")

    for solution in solutions:
        print(solution)
        print()

else:
    print("One solution found:")
    print(solutions[0])

print()
