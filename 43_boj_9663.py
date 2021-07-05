n = int(input())

ground = [[0]*n for i in range(n)]
cnt = 0

def check_queen(row,col) :
    for i in range(n) :
        if ground[row][i] == 1 :
            return False
        if ground[i][col] == 1 :
            return False
        if 0 <= row-i < n and 0 <= col+i < n and ground[row-i][col+i] == 1 :
            return False
        if 0 <= row-i < n and 0 <= col-i < n and ground[row-i][col-i] == 1 :
            return False
    return True

def backtracking(row) :
    global cnt
    for col in range(n) :
        if check_queen(row,col) :
            if row == n-1 :
                cnt += 1
                return
            ground[row][col] = 1
            backtracking(row+1)
            ground[row][col] = 0

backtracking(0)
print(cnt)