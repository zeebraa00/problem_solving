n = int(input())

body = []
for i in range(n) :
    w,h = map(int, input().split())
    body.append([w,h])

answer = []
for i in range(n) :
    w = body[i][0]
    h = body[i][1]
    cnt = 1
    for j in range(n) :
        if w < body[j][0] and h < body[j][1] :
            cnt += 1
    answer.append(str(cnt))

print(" ".join(answer))