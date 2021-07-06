n = int(input())
num = list(map(int,input().split()))
sum_list = []
visited = [0]*10000000
iter = 0

def dfs(idx,sum) :
    if idx == n :
       return
    sum += num[idx]
    sum_list.append(sum)
    visited[sum] = 1
    dfs(idx+1, sum)
    dfs(idx+1, sum-num[idx])

dfs(0,0)
print(visited[1:].index(0)+1)