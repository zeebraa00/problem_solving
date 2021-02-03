import sys

n,m = map(int, input().split())
arr = list(map(int, sys.stdin.readline().split()))
arr_sum=[]

arr_sum.append(arr[0])

for i in range(1,n) :
    arr_sum.append(arr_sum[i-1] + arr[i])

arr_sum.insert(0,0)

for i in range(m) :
    start, end = map(int, sys.stdin.readline().split())
    print(arr_sum[end]-arr_sum[start-1])