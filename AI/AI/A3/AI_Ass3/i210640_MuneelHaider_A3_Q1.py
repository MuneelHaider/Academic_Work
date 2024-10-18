# Muneel Haider
# i21-0640 - G
# AI - Assignment 3

# Notes:
# 1. The best move's position will be shown with the symbol '$'.
# 2. If moveVal == 0, then it is a no-win move.
# 3. If moveVal == 10 then it is a winning move, and the board is displayed.
# 4. If moveVal == -10 then it is a losing move, meaning you have already lost the game.
# 5. The board will be displayed only on winning or tie sitaution.

# You change the symbol of the player and the enemy here
player = 'x'
enemy = 'o'

def isMovesLeft(board):
    for i in range(3):
        for j in range(3):

            if (board[i][j] == '_'):
                return True
    
    return False

def evaluate(board):
    # Checking boardRows for moves
    for boardRow in range(3):
    
        if (board[boardRow][0] == board[boardRow][1] == board[boardRow][2]):
    
            if (board[boardRow][0] == player):
                return 10
    
            elif (board[boardRow][0] == enemy):
                return -10

    # Checking boardColumnumns for moves   
    for boardColumn in range(3):
    
        if (board[0][boardColumn] == board[1][boardColumn] == board[2][boardColumn]):
    
            if (board[0][boardColumn] == player):
                return 10
    
            elif (board[0][boardColumn] == enemy):
                return -10

    # Checking diagonals for moves
    if (board[0][0] == board[1][1] == board[2][2]):
    
        if (board[0][0] == player):
            return 10
    
        elif (board[0][0] == enemy):
            return -10

    if (board[0][2] == board[1][1] == board[2][0]):
    
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

        # Alpha Pruning
        best = -100000
    
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

        # Beta Pruning
        best = 100000
    
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

def printBoard(board, bestMove, moveVal):
    
    if moveVal == 10:
        symbol = '$'
    
    elif moveVal == 0:
        symbol = ' '
    
    else:
        symbol = '$'

    print("\nBoard:")
    print("    0    1    2 ")
    
    for i in range(3):
        print(i, end="  ")
    
        for j in range(3):
    
            if (i, j) == bestMove:
                print(' ' + '$ ', end=" ")
    
            else:
                print(' ' + board[i][j] + ' ', end=" ")
    
            if j != 2:
                print("|", end="")
    
        print()
        if i != 2:
            print("   -----------")

def findBestMove(board):
    current_score = evaluate(board)
    
    if current_score == 10 or current_score == -10 or not isMovesLeft(board):
        printBoard(board, (-1, -1), current_score)
        return None

    bestVal = -100000
    bestMove = (-1, -1)

    for i in range(3):
        for j in range(3):
    
            if board[i][j] == '_':
                board[i][j] = player
                moveVal = minimax(board, 0, False, -1000000, 1000000)
                board[i][j] = '_'
    
                if moveVal > bestVal:
                    bestMove = (i, j)
                    bestVal = moveVal

    print()
    if(bestVal == -10):
        print("No possible move to win game.")
        return bestMove

    elif(bestVal == 0):
        print("No possible move to win game, but it can lead to a draw.")

    elif(bestVal == 10):
        print("Best possible move found.")

    printBoard(board, bestMove, bestVal)
    return bestMove

board = [
    ['x', 'o', 'x'],
    ['o', 'o', 'x'],
    ['_', '_', '_']
]

bestMove = findBestMove(board)
print("\nThe Optimal Move is :")
print("ROW:", bestMove[0], " COL:", bestMove[1])
print()