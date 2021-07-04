n, m = map(int, input().split())

visited = [0 for i in range(8)]
path = [0 for i in range(8)]

def backtracking(cnt) :
    if cnt == m :
        for i in range(m) :
            print(path[i], end=" ")
        print()
        return

    for i in range(n) :
        if visited[i] == 0 :
            if cnt >= 1 :
                if path[cnt-1] > i+1 :
                    continue
            path[cnt] = i+1
            visited[i] = 1
            backtracking(cnt+1)
            visited[i] = 0


backtracking(0)