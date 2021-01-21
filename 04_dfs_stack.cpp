// 백준 2667번

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int cnt;
int arr[25][25];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

vector<pair<int,int>> v;
vector<int> answer;

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j]==1) {
                cnt=0;
                arr[i][j]=0;
                v.push_back(make_pair(i,j));

                while(!v.empty()) {
                    cnt++;
                    pair<int,int> now = v.back();
                    v.pop_back();
                    for (int k=0; k<4; k++) {
                        int nx = now.first + dx[k];
                        int ny = now.second + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (arr[nx][ny]==1) {
                                arr[nx][ny]=0;
                                v.push_back(make_pair(nx,ny));
                            }
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());
    int size = answer.size();

    printf("%d\n", size);

    for (auto iter=answer.begin(); iter != answer.end(); ++iter) {
        printf("%d\n", *iter);
    }

    return 0;
}