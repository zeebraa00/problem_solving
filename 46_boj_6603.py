numbers = []

def dfs(start, cnt) :
    if cnt == 6 :
        iter = len(numbers)
        for i in range(iter) :
            print(numbers[i], end=" ")
        print()
        return
    
    for i in range(start, k) :
        if visited[i] == 1 :
            continue
        visited[i] = 1
        numbers.append(lotto[i])
        dfs(i, cnt+1)
        visited[i] = 0
        numbers.remove(lotto[i])

while True :
    k, *lotto = list(map(int, input().split()))
    if k==0 :
        break
    visited = [0]*k
    dfs(0, 0)
    print()