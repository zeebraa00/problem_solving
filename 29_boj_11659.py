import sys

n,m = map(int, input().split())
arr = list(map(int, sys.stdin.readline().split()))
arr_sum=[0 for i in range(n)]

for i in range(n) :
    if i==0 :
        arr_sum[i] = arr[i]
    else :
        arr_sum[i] = arr_sum[i-1] + arr[i]

arr_sum.insert(0,0)

for i in range(m) :
    start, end = map(int, sys.stdin.readline().split())
    print(arr_sum[end]-arr_sum[start-1])