#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int map[25][25];
int chk[25][25]={0,}; // 방문하면 1로 변경

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int cnt;
vector<int> answer;

void dfs(int x, int y) {
    cnt++;
    chk[x][y]=1;

    for (int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];

        if (0<=nx && nx < n && 0<=ny && ny < n) {
            if (map[nx][ny]==1 && chk[nx][ny]==0) {
                dfs(nx,ny);
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ( map[i][j]==1 && chk[i][j]==0 ) {
                cnt=0;
                dfs(i,j);
                answer.push_back(cnt);
            }
        }
    }

    int size = answer.size();
    sort(answer.begin(), answer.end());
    printf("%d\n",size);

    for (auto iter=answer.begin(); iter!=answer.end(); ++iter) {
        printf("%d\n", *iter);
    }

    return 0;
}