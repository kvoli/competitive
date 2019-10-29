
from collections import defaultdict
def findWords(board, words):
    def letter_check(letter, i, j, seen, board):
        return (tuple([i, j]) not in seen) and (i < len(board)) and (j < len(board[0])) and (i > -1) and (j > -1) and (board[i][j] == letter)
        
    def wordSearch(word, i, j, seen, board):
        if not word:
            return True
        elif not letter_check(word[0], i, j, seen, board):
            return False
        else:
            new_seen = seen.copy() 
            new_seen.add(tuple([i, j]))
            word = word[1:]
            return any((wordSearch(word, i+1, j, new_seen, board), wordSearch(word, i-1, j, new_seen, board), wordSearch(word, i, j+1, new_seen, board), wordSearch(word, i, j-1, new_seen, board)))
    
    
    res = []
    starting_positions = defaultdict(list)
    for i in range(len(board)):
        for j in range(len(board[0])):
            starting_positions[board[i][j]].append(tuple([i,j]))
    for word in words:
            starter = starting_positions.get(word[0], False)
            if starter:
                for i in starter:
                    if wordSearch(word, i[0], i[1], set(), board):
                        res.append(word)
                        break
    return starting_positions


board = [["a","b"]]
words = ["ba"]


# words = ["oath","pea","eat","rain"]
# wor = ["eat"]
print(findWords(board, words))