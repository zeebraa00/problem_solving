// 백준 2178번

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int map[100][100];
int visited[100][100];
int chk[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int x, int y) {
    visited[x][y]=1;
    queue< pair<int,int> > q;
    q.push(make_pair(x,y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (map[nx][ny] == 1 && visited[nx][ny]==0) {
                    chk[nx][ny]=chk[x][y]+1;
                    visited[nx][ny]=1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&map[i][j]);
        }
    }
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            visited[i][j]=0;
            chk[i][j]=0;
        }
    }
    chk[0][0]=1;
    bfs(0,0);
    printf("%d\n",chk[n-1][m-1]);

    return 0;
}