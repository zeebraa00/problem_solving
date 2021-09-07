iters = int(input())

for i in range(iters) :
    n, m = map(int, input().split())
    q = n // m
    arr = [q]*m
    r = n % m
    for j in range(r) :
        arr[j] += 1
    
    output = 1
    for j in range(m) :
        output *= arr[j]
    
    print("#"+str(i+1)+" "+str(output))