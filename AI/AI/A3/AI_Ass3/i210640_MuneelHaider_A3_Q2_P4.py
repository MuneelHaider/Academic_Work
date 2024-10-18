# Muneel Haider
# i21-0640 - G
# AI - Assignment 3

import random

player = 'x'
enemy = 'o'

def isMovesLeft(board):
    
    for i in range(3):
        for j in range(3):
  
            if (board[i][j] == '_'):
                return True
  
    return False

def evaluate(board):
    for boardRow in range(3):
     
        if (board[boardRow][0] == board[boardRow][1] and board[boardRow][1] == board[boardRow][2]):
     
            if (board[boardRow][0] == player):
                return 10
     
            elif (board[boardRow][0] == enemy):
                return -10

    for boardColumn in range(3):
    
        if (board[0][boardColumn] == board[1][boardColumn] and board[1][boardColumn] == board[2][boardColumn]):
    
            if (board[0][boardColumn] == player):
                return 10
    
            elif (board[0][boardColumn] == enemy):
                return -10

    if (board[0][0] == board[1][1] and board[1][1] == board[2][2]):
    
        if (board[0][0] == player):
            return 10
    
        elif (board[0][0] == enemy):
            return -10

    if (board[0][2] == board[1][1] and board[1][1] == board[2][0]):
    
        if (board[0][2] == player):
            return 10
    
        elif (board[0][2] == enemy):
            return -10

    return 0

def minimax(board, depth, isMax, boardAlpha, boardBeta):
    score = evaluate(board)

    if (score == 10) or (score == -10):
        return score

    if not isMovesLeft(board):
        return 0

    if isMax:
        best = -1000
    
        for i in range(3):
            for j in range(3):
    
                if board[i][j] == '_':
                    board[i][j] = player
                    best = max(best, minimax(board, depth + 1, not isMax, boardAlpha, boardBeta))
                    board[i][j] = '_'
                    boardAlpha = max(boardAlpha, best)
    
                    if boardBeta <= boardAlpha:
                        break
        return best
    
    else:
        best = 1000
    
        for i in range(3):
            for j in range(3):
    
                if board[i][j] == '_':
                    board[i][j] = enemy
                    best = min(best, minimax(board, depth + 1, not isMax, boardAlpha, boardBeta))
                    board[i][j] = '_'
                    boardBeta = min(boardBeta, best)
    
                    if boardBeta <= boardAlpha:
                        break
        return best

def findRandomMove(board, TileNotForWeakAI):
    available_moves = [(i, j) for i in range(3) for j in range(3) if board[i][j] == '_' and (i, j) != TileNotForWeakAI]
    return random.choice(available_moves) if available_moves else None

def weakAIPlay(board, TileNotForWeakAI):
    bestVal = -1000
    bestMove = (-1, -1)
    
    while isMovesLeft(board):
        move = findRandomMove(board, TileNotForWeakAI)
    
        if move:
            board[move[0]][move[1]] = player
            bestMove = move
            bestVal = evaluate(board)
            printBoard(board, bestMove, bestVal)
    
            if bestVal == 10:
                print("Weak AI player wins!")
                return
    
            elif bestVal == -10:
                print("Weak AI player loses!")
                return
    
        else:
            print("It's a tie!")
            return
    
        enemy_move = findRandomMove(board, TileNotForWeakAI)
    
        if enemy_move:
            board[enemy_move[0]][enemy_move[1]] = enemy
            printBoard(board, enemy_move, -evaluate(board))

def printBoard(board, lastMove, moveVal):
    print("\nBoard after the last move:")
    
    for i in range(3):
        for j in range(3):
    
            if (i, j) == lastMove:
                print(f' ${board[i][j]}$ ', end="")
    
            else:
                print(f'  {board[i][j]}  ', end="")
    
            if j != 2:
                print("|", end="")
    
        print()
    
        if i != 2:
            print("---------------")

board = [
    ['_', '_', '_'],
    ['_', '_', '_'],
    ['_', '_', '_']
]

TileNotForWeakAI = (random.randint(0, 2), random.randint(0, 2))
print(f"Forbidden tile for the AI: {TileNotForWeakAI}")
weakAIPlay(board, TileNotForWeakAI)
