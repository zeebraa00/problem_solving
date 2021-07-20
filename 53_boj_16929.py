n,m = map(int, input().split())
color = []
ground = []
visited = [[0]*m for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for _ in range(n) :
    buf = list(input())
    for i in range(m) :
        if buf[i] not in color :
            color.append(buf[i])
    ground.append(buf)

start_x=0
start_y=0
cur_color = 0

def dfs(cnt, x, y) :
    global cur_color

    # print("path : ", x, y, cur_color)
    if cnt >= 4 and x == start_x and y == start_y :
        print("Yes")
        exit(0)
    
    cur_color = ground[x][y]
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and ground[nx][ny] == cur_color and visited[nx][ny] == 0 :
            visited[nx][ny] = 1
            dfs(cnt+1, nx, ny)
            visited[nx][ny] = 0

for i in range(n) :
    for j in range(m) :
        # print("="*10)
        start_x=i
        start_y=j
        dfs(0,i,j)
print("No")