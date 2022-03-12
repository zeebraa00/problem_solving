import math

n,k = map(int, input().split())
if k == 1 :
    print("1")
    exit()

ceil = math.ceil(math.sqrt(n))

divisors = [1,n]
for i in range(2,ceil+1) :
    if i in divisors :
        continue
    if n % i == 0 :
        divisors.append(i)
        if n//i in divisors :
            continue
        divisors.append(n//i)

if len(divisors) < k :
    print("0")
else :
    divisors.sort()
    # print(divisors)
    print(divisors[k-1])