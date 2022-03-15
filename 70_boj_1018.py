n,m = map(int, input().split())

start_w = [[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0]]
start_b = [[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1],[1,0,1,0,1,0,1,0],[0,1,0,1,0,1,0,1]]

def count_diff(arr) :
    cnt_w = 0
    cnt_b = 0
    for i in range(8) :
        for j in range(8) :
            if arr[i][j] != start_w[i][j] :
                cnt_w += 1
            if arr[i][j] != start_b[i][j] :
                cnt_b += 1
    return min(cnt_w, cnt_b)

chess_map = []
for _ in range(n) :
    buffer = []
    buf = input()
    for i in range(m) :
        if buf[i] == "W" :
            buffer.append(0)
        else :
            buffer.append(1)
    chess_map.append(buffer)

x_remain = m - 8
y_remain = n - 8

minimum_value = 64
for i in range(x_remain+1) :
    for j in range(y_remain+1) :
        selected = [row[i:i+8] for row in chess_map[j:j+8]]
        cnt = count_diff(selected)
        if minimum_value > cnt :
            minimum_value = cnt

print(minimum_value)