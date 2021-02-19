n, m = map( int, input().split() )
num=[]
ans=[]

for i in range(n) :
    num.append(list(map(int, input())))

for i in range(1,n) :
    for j in range(1,m) :
        if num[i][j] == 1 :
            num[i][j] = min(num[i-1][j-1], min(num[i][j-1],num[i-1][j])) + 1

for i in range(n) :
    ans.extend(num[i])

print(pow(max(ans),2))