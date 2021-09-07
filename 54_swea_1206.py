def check_window(i,arr) :
    compare = max(arr[i-2],arr[i-1],arr[i+1],arr[i+2])
    value = (arr[i] - compare) if arr[i] - compare > 0 else 0
    return value

for idx in range(10) :
    testcase = int(input())
    buf = list(map(int,input().split()))
    sum=0
    for i in range(2, testcase-2) :
        sum += check_window(i, buf)
    print("#"+str(idx+1)+" "+str(sum))