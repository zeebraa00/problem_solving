#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int knight(int m, int x1, int y1, int x2, int y2) {
    // dynamic declaring
    int **chk = new int* [m];
    for (int i=0; i<m; i++) {
        chk[i] = new int [m];
    }

    int **visited = new int* [m];
    for (int i=0; i<m; i++) {
        visited[i] = new int [m];
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            chk[i][j]=0;
            visited[i][j]=0;
        }
    }

    queue< pair<int,int> > q;
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};

    visited[x1][y1]=1;
    q.push(make_pair(x1,y1));

    int x,y,nx,ny;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == x2 && y == y2) {
            int ans = chk[x][y];
            delete chk;
            delete visited;
            return ans;
        }

        for (int i=0; i<8; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < m && visited[nx][ny]==0) {
                q.push(make_pair(nx,ny));
                visited[nx][ny]=1;
                chk[nx][ny]= chk[x][y]+1;
            }
        }
    }

    return -1;
}

int main(int argc, char **argv) {
    int n; // # testcase
    int m; // size of ground
    int x1,y1,x2,y2; // from coord to coord

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &m);
        scanf("%d %d", &x1, &y1);
        scanf("%d %d", &x2, &y2);

        printf("%d\n", knight(m,x1,y1,x2,y2));
    }

    return 0;
}