import sys

arr = [0]*10001
n = int(sys.stdin.readline())

for _ in range(n) :
    arr[int(sys.stdin.readline())] += 1

for i in range(1,10001) :
    for j in range(arr[i]) :
        print(i)