#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n; // 정사각형의 변의 길이
int map[25][25];
int chk[25][25]={0,};
int groupId=-1;
vector<int> group;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y) {
    chk[x][y]=1;
    group[groupId]++;

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ( 0 <= nx && nx < n && 0 <= ny && ny < n ) {
            if (map[nx][ny] == 1 && chk[nx][ny] == 0) {
                dfs(nx,ny);
            }
        }
    }
    
    // for (auto iter=group.begin(); iter!=group.end(); ++iter) {
    //     cout << *iter;
    // }
    // cout << endl;
}

int main() {
    // ios::sync_with_stdio(false);

    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // 입력을 1개씩 숫자로 끊어서 받기 -> %1d
            scanf("%1d", &map[i][j]);
        }
    }

    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            if (map[x][y]==1 && chk[x][y]==0) {
                groupId++;
                group.push_back(0);
                dfs(x,y);
            }
        }
    }

    sort(group.begin(),group.end());
    cout << group.size() << "\n";
    for (auto iter=group.begin(); iter != group.end(); ++iter) {
        cout << *iter << "\n";
    }

    return 0;
}