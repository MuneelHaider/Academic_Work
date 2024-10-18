# Muneel Haider
# i21-0640 - G
# AI - Assignment 3

player = 'x'
enemy = 'o'
countNodes = 0

def isMovesLeft(board):
    for i in range(3):
        for j in range(3):
      
            if board[i][j] == '_':
                return True
    
    return False

def evaluate(board):
    
    for i in range(3):
    
        if board[i][0] == board[i][1] == board[i][2] != '_':
            return 10 if board[i][0] == player else -10
    
    return 0

def minimax(board, depth, isMax, boardAlpha=None, boardBeta=None, use_pruning=False):
    global countNodes
    countNodes += 1

    score = evaluate(board)
    
    if score == 10 or score == -10 or not isMovesLeft(board):
        return score

    if isMax:
        best = -100000
    
        for i in range(3):
            for j in range(3):
    
                if board[i][j] == '_':
                    board[i][j] = player
                    value = minimax(board, depth+1, False, boardAlpha, boardBeta, use_pruning)
                    board[i][j] = '_'
                    best = max(best, value)
    
                    if use_pruning:
                        boardAlpha = max(boardAlpha, best)
    
                        if boardBeta is not None and boardBeta <= boardAlpha:
                            break
        return best
    
    else:
        best = 100000
    
        for i in range(3):
            for j in range(3):
    
                if board[i][j] == '_':
                    board[i][j] = enemy
                    value = minimax(board, depth+1, True, boardAlpha, boardBeta, use_pruning)
                    board[i][j] = '_'
                    best = min(best, value)
    
                    if use_pruning:
                        boardBeta = min(boardBeta, best)
    
                        if boardAlpha is not None and boardBeta <= boardAlpha:
                            break
        return best

def compare_minimax(board):
    global countNodes
    result = {"Without Pruning": [], "With Pruning": []}

    for _ in range(3):
        countNodes = 0
        minimax(board, 0, True)
        result["Without Pruning"].append(countNodes)

        countNodes = 0
        minimax(board, 0, True, -100000, 100000, True)
        result["With Pruning"].append(countNodes)

    return result

board = [
    ['x', '_', 'x'],
    ['_', 'o', 'x'],
    ['_', '_', '_']
]

result = compare_minimax(board)
print("\nNode counts comparison: \n", result, "\n")
