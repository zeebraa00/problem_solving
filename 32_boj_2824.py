import sys
sys.setrecursionlimit(10**9)

def gcd(x,y) :
    if y !=0 :
        return gcd(y,x%y)
    else :
        return x

n = int(sys.stdin.readline())
tmp = list(map(int, sys.stdin.readline().split()))
n1=1
for i in range(n) :
    n1 *= tmp[i]

m = int(sys.stdin.readline())
tmp = list(map(int, sys.stdin.readline().split()))
n2=1
for i in range(m) :
    n2 *= tmp[i]

if (n1<n2) :
    result = gcd(n2,n1)
else :
    result = gcd(n1,n2)

if len(str(result)) > 9 :
    print(str(result)[-9:-1]+str(result)[-1])
else :
    print(result)