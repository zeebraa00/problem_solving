#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int x,y,dir;
int cnt=1; // 방문한 점의 개수
pair<int,int> coordinates;
vector<pair<int,int>> direction;

int array[50][50]; // 지도
int check[50][50]; // 0인 곳만 갈 수 있음

int chkArray() { // 해당 방향 한 칸 앞으로 갈 수 있는지 확인
    if (check[coordinates.first+direction[dir].first][coordinates.second+direction[dir].second] == 0 && array[coordinates.first+direction[dir].first][coordinates.second+direction[dir].second] == 0 ) {
        return 1; // 감
    } else {
        return 0; // 못 감
    }
}

int chkReverse() { // 해당 방향 한 칸 뒤로 갈 수 있는지 확인
    if (array[coordinates.first-direction[dir].first][coordinates.second-direction[dir].second] == 1) {
        return 0; // 못 감
    } else {
        return 1; // 감
    }
}

void move() { // 현재 방향이 dir일 때 앞으로 가는 함수
    int turnTime=0;
    check[coordinates.first][coordinates.second]=1;
    while (true) {
        dir--;
        if (dir<0) {
            dir+=4;
        }
        if ( chkArray() ) {
            coordinates.first += direction[dir].first;
            coordinates.second += direction[dir].second;
            check[coordinates.first][coordinates.second]=1;
            cnt++;
            turnTime=0;
        } else {
            turnTime++;
        }
        if (turnTime==4) {
            if ( chkReverse() ) {
                coordinates.first -= direction[dir].first;
                coordinates.second -= direction[dir].second;
                check[coordinates.first][coordinates.second]=1;
                turnTime=0;
            } else {
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    for (int i=0; i<50; i++) {
        for (int j=0; j<50; j++) {
            array[i][j] = 1;
            check[i][j] = 1;
        }
    }

    cin >> n >> m;
    cin >> x >> y >> dir;

    coordinates = make_pair(x,y);
    direction.push_back(make_pair(1,0));
    direction.push_back(make_pair(0,1));
    direction.push_back(make_pair(-1,0));
    direction.push_back(make_pair(0,-1));

    int buff;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> buff;
            array[i][j] = buff;
            check[i][j] = buff;
        }
    }
    move();
    printf("%d\n",cnt);

    return 0;
}

/*

4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1

*/