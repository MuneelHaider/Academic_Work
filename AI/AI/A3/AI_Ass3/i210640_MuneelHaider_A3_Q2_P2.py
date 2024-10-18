# Muneel Haider
# i21-0640 - G
# AI - Assignment 3

import threading
import copy
import time

player = 'x'
enemy = 'o'

def evaluate(board):
    for boardRow in range(3):
   
        if board[boardRow][0] == board[boardRow][1] == board[boardRow][2] != '_':
   
            if board[boardRow][0] == player:
                return 10
   
            elif board[boardRow][0] == enemy:
                return -10

    for boardColumn in range(3):
   
        if board[0][boardColumn] == board[1][boardColumn] == board[2][boardColumn] != '_':
   
            if board[0][boardColumn] == player:
                return 10
   
            elif board[0][boardColumn] == enemy:
                return -10

    if board[0][0] == board[1][1] == board[2][2] != '_':
   
        if board[0][0] == player:
            return 10
   
        elif board[0][0] == enemy:
            return -10

    if board[0][2] == board[1][1] == board[2][0] != '_':
   
        if board[0][2] == player:
            return 10
   
        elif board[0][2] == enemy:
            return -10

    return 0

def isMovesLeft(board):

    for i in range(3):
        for j in range(3):

            if board[i][j] == '_':
                return True
    return False

def minimax(board, depth, isMax, boardAlpha, boardBeta):
    score = evaluate(board)

    if score == 10 or score == -10:
        return score

    if not isMovesLeft(board):
        return 0

    if isMax:
        best = -100000

        for i in range(3):
            for j in range(3):

                if board[i][j] == '_':
                    board[i][j] = player
                    best = max(best, minimax(board, depth+1, not isMax, boardAlpha, boardBeta))
                    board[i][j] = '_'
                    boardAlpha = max(boardAlpha, best)

                    if boardBeta <= boardAlpha:
                        break
        return best

    else:
        best = 100000

        for i in range(3):
            for j in range(3):

                if board[i][j] == '_':
                    board[i][j] = enemy
                    best = min(best, minimax(board, depth+1, isMax, boardAlpha, boardBeta))
                    board[i][j] = '_'
                    boardBeta = min(boardBeta, best)

                    if boardAlpha >= boardBeta:
                        break
        return best

def parallel_minimax(board, isMax):
    results = {}
    boardAlpha, boardBeta = -100000, 100000

    def worker(board, i, j):
        new_board = copy.deepcopy(board)
        new_board[i][j] = player if isMax else enemy
        move_score = minimax(new_board, 0, not isMax, boardAlpha, boardBeta)
        results[(i, j)] = move_score

    threads = []

    for i in range(3):
        for j in range(3):

            if board[i][j] == '_':
                t = threading.Thread(target=worker, args=(board, i, j))
                threads.append(t)
                t.start()
    
    for t in threads:
        t.join()

    best_move = max(results, key=results.get) if isMax else min(results, key=results.get)

    return best_move, results[best_move]

board = [
    ['x', '_', 'x'],
    ['_', 'o', '_'],
    ['_', '_', '_']
]

# Sequential Minimax
startTime = time.perf_counter()
bestSolution = minimax(board, 0, True, -100000, 100000)
endTime = time.perf_counter()
print(f"\nSequential Minimax Best Value: {bestSolution}, Time Taken: {endTime - startTime}")

# Parallel Minimax
startTime = time.perf_counter()
best_move, bestSolution = parallel_minimax(board, True)
endTime = time.perf_counter()
print(f"\nParallel Minimax Best Value: {bestSolution}, Time Taken: {endTime - startTime}")
print()