n = int(input())
seq = list(map(int, input().split()))
oper = list(map(int, input().split()))
max_val = -10000000000
min_val = 10000000000

def dfs(cnt, val) :
    global max_val, min_val

    if cnt == n-1 :
        if val > max_val :
            max_val = val
        if val < min_val :
            min_val = val
        return
    
    for i in range(4) :
        if oper[i] == 0 :
            continue
        oper[i] -= 1
        if i==0 :
            next = val + seq[cnt+1]
        elif i==1 :
            next = val - seq[cnt+1]
        elif i==2 :
            next = val * seq[cnt+1]
        else :
            next = int(val / seq[cnt+1])
        dfs(cnt+1, next)
        oper[i] += 1

dfs(0,seq[0])
print(max_val)
print(min_val)