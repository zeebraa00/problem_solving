n = int(input())

history = []

def hanoi(start, dest, num) :
    arr = [1,2,3]
    arr.remove(start)
    arr.remove(dest)
    stop = arr[0]
    if num == 1 :
        history.append((start,dest))
        return
    hanoi(start, stop, num-1)
    history.append((start,dest))
    hanoi(stop, dest, num-1)

hanoi(1,3,n)
print(len(history))
for i in history :
    print(f"{i[0]} {i[1]}")