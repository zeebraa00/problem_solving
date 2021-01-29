array=[]
sum = 0
count = 0

N, M, K = map(int, input().split())
array = list(map(int, input().split()))

array.sort(reverse=True)

while True :
    for i in range(K) :
        sum += array[0]
        count += 1
        if count == M :
            break
    sum += array[1]
    count += 1
    if count == M :
        break

print(sum)