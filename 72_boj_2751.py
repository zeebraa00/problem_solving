from queue import PriorityQueue
import sys

pq = PriorityQueue()
n = int(sys.stdin.readline())

for _ in range(n) :
    pq.put(int(sys.stdin.readline()))

for _ in range(n) :
    print(pq.get())