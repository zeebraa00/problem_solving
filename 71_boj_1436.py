n = int(input())

cnt = 0
now = 665
while True :
    now += 1
    if cnt == n :
        print(now-1)
        break
    if '666' in str(now) :
        cnt += 1