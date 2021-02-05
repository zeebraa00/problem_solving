import sys

n = int(sys.stdin.readline())
arr=[]
dp=[0 for i in range(n)]

for i in range(n) :
    tmp = int(sys.stdin.readline())
    arr.append(tmp)

if n>3 :
    dp[0] = arr[0]
    dp[1] = arr[0] + arr[1]
    dp[2] = max(arr[0]+arr[2], arr[1]+arr[2])

    for i in range(3,n) :
        dp[i] = max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i])
        
    print(dp[n-1])

elif n==3 :
    print(max(arr[0]+arr[2], arr[1]+arr[2]))
elif n==2 :
    print(arr[0] + arr[1])
else :
    print(arr[0])
