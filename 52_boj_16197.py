from collections import deque

n,m = map(int, input().split())
ground = [[0]*m for _ in range(n)]
visited = [[0]*m for _ in range(n)]

pos = []
q = deque()
dx = [1, -1, 0, 0]
dy = [0, 0, 1 ,-1]

for i in range(n) :
    buf = input()
    for j in range(m) :
        item = buf[j]
        if item == "o" :
            pos.append([i,j])
        elif item == "#" :
            visited[i][j] = 1

def bfs() :
    while (len(q) != 0) :
        cnt, x1, y1, x2, y2 = q.popleft()

        if cnt >= 10 :
            return -1

        for i in range(4) :
            nx1 = x1 + dx[i]
            ny1 = y1 + dy[i]
            nx2 = x2 + dx[i]
            ny2 = y2 + dy[i]

            if 0 <= nx1 < n and 0 <= ny1 < m and 0 <= nx2 < n and 0 <= ny2 < m :
                if visited[nx1][ny1] == 1 :
                    nx1, ny1 = x1, y1
                if visited[nx2][ny2] == 1 :
                    nx2, ny2 = x2, y2
                q.append([cnt+1,nx1,ny1,nx2,ny2])            
            elif 0 <= nx1 < n and 0 <= ny1 < m :
                return cnt+1
            elif 0 <= nx2 < n and 0 <= ny2 < m :
                return cnt+1
    return -1

q.append([0,pos[0][0],pos[0][1],pos[1][0],pos[1][1]])
print(bfs())