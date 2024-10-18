# Muneel Haider
# i21-0640 - G
# AI - Assignment 3

import time

player = 'x'
enemy = 'o'

def isMovesLeft(board):
    
    for i in range(3):
        for j in range(3):
    
            if board[i][j] == '_':
                return True
    
    return False

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

def heuristic(board):
    
    hueScore = 0
    
    for i in range(3):
    
        if board[i].count(player) == 2 and board[i].count('_') == 1:
            hueScore += 1
    
        if board[i].count(enemy) == 2 and board[i].count('_') == 1:
            hueScore -= 1

    for boardColumn in range(3):
        colNumber = [board[i][boardColumn] for i in range(3)]
    
        if colNumber.count(player) == 2 and colNumber.count('_') == 1:
            hueScore += 1
    
        if colNumber.count(enemy) == 2 and colNumber.count('_') == 1:
            hueScore -= 1

    diagonal1 = [board[i][i] for i in range(3)]
    diagonal2 = [board[i][2 - i] for i in range(3)]
    
    if diagonal1.count(player) == 2 and diagonal1.count('_') == 1:
        hueScore += 1
    
    if diagonal1.count(enemy) == 2 and diagonal1.count('_') == 1:
        hueScore -= 1
    
    if diagonal2.count(player) == 2 and diagonal2.count('_') == 1:
        hueScore += 1
    
    if diagonal2.count(enemy) == 2 and diagonal2.count('_') == 1:
        hueScore -= 1

    return hueScore

def minimax(board, depth, isMax, boardAlpha, boardBeta):
    global nodeCount
    nodeCount += 1

    if depth == 0 or not isMovesLeft(board):
        return heuristic(board)

    score = evaluate(board)
    
    if score == 10 or score == -10:
        return score

    if isMax:
        best = -100000
    
        for i in range(3):
            for j in range(3):
    
                if board[i][j] == '_':
                    board[i][j] = player
                    best = max(best, minimax(board, depth-1, not isMax, boardAlpha, boardBeta))
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
                    best = min(best, minimax(board, depth-1, isMax, boardAlpha, boardBeta))
                    board[i][j] = '_'
                    boardBeta = min(boardBeta, best)
    
                    if boardAlpha >= boardBeta:
                        break
        return best

def findBestMove(board):
    bestVal = -1000
    bestMove = (-1, -1)

    for i in range(3):
        for j in range(3):

            if board[i][j] == '_':
                board[i][j] = player
                moveVal = minimax(board, 0, False, -100000, 100000)
                board[i][j] = '_'

                if moveVal > bestVal:
                    bestMove = (i, j)
                    bestVal = moveVal
    return bestMove

board = [
    ['x', 'o', 'x'],
    ['o', '_', 'x'],
    ['o', '_', '_']
]

nodeCount = 0
startTime = time.perf_counter()
bestMove = findBestMove(board)
endTime = time.perf_counter()

print("The Optimal Move is:", bestMove)
print("Heuristic minimax result:", nodeCount)
print("Heuristic minimax time taken:", endTime - startTime)
