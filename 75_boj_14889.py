import sys
from itertools import combinations

n = int(sys.stdin.readline())

arr = []
for _ in range(n) :
    buf = list(map(int, sys.stdin.readline().split()))
    arr.append(buf)

mini = 200
def make_team() :
    global mini
    team_a_list = list(combinations([i for i in range(n)],n//2))
    for team_a in team_a_list :
        team_a = list(team_a)
        team_b = []
        score_a = 0
        score_b = 0
        for i in range(n) :
            if i in team_a :
                continue
            team_b.append(i)
        for i in range(n//2) :
            for j in range(n//2) :
                if i == j :
                    continue
                score_a += arr[team_a[i]][team_a[j]]
                score_b += arr[team_b[i]][team_b[j]]
        diff = score_a - score_b if score_a > score_b else score_b - score_a
        if diff < mini :
            mini = diff

make_team()
print(mini)