from itertools import combinations

n,m = map(int,input().split())
arr = list(combinations([str(i) for i in range(1,n+1)],m))

for item in arr :
    print(" ".join(item))