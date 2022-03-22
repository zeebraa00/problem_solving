n,m = map(int,input().split())

visited = [0]*(n+1)
arr = []

def backtracking(depth) :
    if depth == m :
        print(" ".join(arr))
        return
    for i in range(1, n+1) :
        if visited[i] == 1 :
            continue
        if depth != 0 and int(arr[depth-1]) > i :
            continue
        visited[i] = 1
        arr.append(str(i))
        backtracking(depth+1)
        visited[i] = 0
        arr.remove(str(i))

backtracking(0)