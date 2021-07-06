import sys

t = int(input())
cnt=0

def recruit() :
    global cnt
    score = []
    n = int(input())
    cnt = 1

    for _ in range(n) :
        a,b = map(int, sys.stdin.readline().split())
        score.append([a,b])
    score.sort()

    min = score[0][1]
    for i in range(1,n) :
        if min > score[i][1] :
            min = score[i][1]
            cnt += 1

for _ in range(t) :
    recruit()
    print(cnt)