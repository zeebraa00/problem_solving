tc = int(input())

for idx in range(tc) :
    tmp = []
    goal = int(input())
    string = input()
    iters = len(string)
    for i in range(iters) :
        tmp.append(string[i:])
    tmp.sort()
    if len(tmp) < goal :
        print("#"+str(idx+1)+" none")
        continue
    print("#"+str(idx+1)+" "+tmp[goal-1])