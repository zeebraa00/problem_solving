import sys
from queue import PriorityQueue

arr = [0] * 8001
pq = PriorityQueue()
n = int(sys.stdin.readline())
summ = 0

for _ in range(n) :
    buf = int(sys.stdin.readline())
    summ += buf
    arr[buf + 4000] += 1
    pq.put(buf)

print(round(summ/n))

first = 0;last = 0
freq_value = []
freq_cnt = 0

for i in range(n) :
    now = pq.get()
    if arr[now + 4000] > freq_cnt :
        freq_cnt = arr[now + 4000]
        freq_value = [now]
    elif arr[now + 4000] == freq_cnt :
        freq_value.append(now)
        
    if i == 0 :
        first = now
    if i == (n//2) :
        print(now)
    if i == n-1 :
        last = now

freq_value = list(set(freq_value))
freq_value.sort()

try :
    print(freq_value[1])
except :
    print(freq_value[0])

print(last-first)