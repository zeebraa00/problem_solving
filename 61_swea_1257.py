tc = int(input())

for idx in range(tc) :
    tmp = []
    goal = int(input())
    string = input()
    iters = len(string)
    for i in range(iters) :
        for j in range(iters - i) :
            tmp.append(string[j:iters - i])
    tmp = list(set(tmp))
    tmp.sort()
    compare = len(tmp)
    if compare < goal :
        print("#"+str(idx+1)+" none")
        continue
    print("#"+str(idx+1)+" "+tmp[goal-1])