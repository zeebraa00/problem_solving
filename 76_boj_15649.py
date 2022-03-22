n,m = map(int, input().split())

visited = [0]*(n+1)
arr = []

def backtracking(depth) :
    if depth == m :
        print(" ".join(arr))
        return
    for i in range(1,n+1) :
        if visited[i] == 1 :
            continue
        arr.append(str(i))
        visited[i] = 1
        backtracking(depth+1)
        arr.remove(str(i))
        visited[i] = 0

backtracking(0)