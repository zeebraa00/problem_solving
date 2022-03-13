n,m = map(int, input().split())
cards = list(map(int, input().split()))

visited = [0]*n
max_sum = 0

def combination(depth, summation) :
    global max_sum
    if depth == 3 :
        if summation <= m :
            if max_sum < summation :
                max_sum = summation
        return
    for i in range(n) :
        if visited[i] == 1 :
            continue
        summation += cards[i]
        visited[i] = 1
        combination(depth+1, summation)
        summation -= cards[i]
        visited[i] = 0

combination(0,0)
print(max_sum)

"""

5,6,7,8,9

"""