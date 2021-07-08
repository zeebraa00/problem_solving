n,m = map(int, input().split())
visited = [[0]*m for _ in range(n)]
ground = []
for i in range(n) :
    ground.append(list(map(int, input().split())))

max_val = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x ,y ,cnt, val) :
    global max_val
    if cnt == 3 :
        if val > max_val :
            max_val = val
        return
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == 0 :
            visited[x][y] = 1
            dfs(nx, ny, cnt+1, val+ground[nx][ny])
            visited[x][y] = 0

def ㅗ(x,y) :
    global max_val
    l = []
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m :
            l.append([nx,ny])
    if len(l) == 3 :
        tmp = ground[x][y]
        for i in range(3) :
            tmp += ground[l[i][0]][l[i][1]]
        if tmp > max_val :
            max_val = tmp
    elif len(l) == 4 :
        tmp = ground[x][y]
        for i in ([0,1,2]) :
            tmp += ground[l[i][0]][l[i][1]]
        if tmp > max_val :
            max_val = tmp
        tmp = ground[x][y]
        for i in ([0,1,3]) :
            tmp += ground[l[i][0]][l[i][1]]
        if tmp > max_val :
            max_val = tmp
        tmp = ground[x][y]
        for i in ([0,2,3]) :
            tmp += ground[l[i][0]][l[i][1]]
        if tmp > max_val :
            max_val = tmp
        tmp = ground[x][y]
        for i in ([1,2,3]) :
            tmp += ground[l[i][0]][l[i][1]]
        if tmp > max_val :
            max_val = tmp

for i in range(n) :
    for j in range(m) :
        visited[i][j] = 0
        dfs(i,j,0,ground[i][j])
        ㅗ(i,j)

print(max_val)