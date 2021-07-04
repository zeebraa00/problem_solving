n, m = map(int, input().split())

path = [0 for i in range(7)]

def backtracking(cnt) :
    if cnt == m :
        for i in range(m) :
            print(path[i], end=" ")
        print()
        return

    for i in range(n) :
        path[cnt] = i+1
        backtracking(cnt+1)

backtracking(0)