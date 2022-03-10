import sys
import math

n = int(sys.stdin.readline())
k = round(math.log(n,3))

arr = [["*"]*n for _ in range(n)]

def erase(row,col,length) :
    for i in range(length) :
        for j in range(length) :
            arr[row+i][col+j] = " "

def draw(row,col,depth) :
    length = 3 ** (depth-1)
    # print(row,col,length)
    erase(row+length, col+length, length)
    if depth == 1 :
        return
    for i in range(9) :
        if i == 4 :
            continue
        n_row = row + (i%3)*length
        n_col = col + (i//3)*length
        draw(n_row, n_col, depth-1)

draw(0,0,k)
for row in arr :
    print("".join(row))