import sys

n,m = map(int, sys.stdin.readline().split())
arr=[]

for i in range(n) :
    buff=list(map(int,sys.stdin.readline().split()))
    buff.insert(0,0)
    arr.append(buff)

arr.insert(0,[0 for i in range(n+1)])

for i in range(1,n+1) :
    for j in range(1,n+1) :
        arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j]

for i in range(m) :
    x1,y1,x2,y2=map(int,sys.stdin.readline().split())
    print(arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1])