n = int(input())
seq = list(map(int, input().split()))
a,b,c,d = map(int, input().split())
output = []
visited = [0]*(n-1)
oper = []
for _ in range(a) :
    oper.append("+")
for _ in range(b) :
    oper.append("-")
for _ in range(c) :
    oper.append("*")
for _ in range(d) :
    oper.append("/")

def dfs(cnt, calc) :
    if cnt == n-1 :
        output.append(calc)
        return
    cnt += 1
    for i in range(n-1) :
        if visited[i] == 1 :
            continue
        visited[i] = 1
        buf = oper[i]
        tmp = calc
        if buf == "+" :
            calc += seq[cnt]
        elif buf == "-" :
            calc -= seq[cnt]
        elif buf == "*" :
            calc *= seq[cnt]
        elif buf == "/" :
            calc = int(calc / seq[cnt])
        dfs(cnt, calc)
        visited[i] = 0
        calc = tmp

dfs(0,seq[0])
output.sort()
print(output[len(output)-1])
print(output[0])