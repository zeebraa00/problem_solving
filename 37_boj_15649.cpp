#include <cstdio>
#include <iostream>
#define MAX 9

using namespace std;

int n,m;
int arr[MAX]; // 방문 순서대로 arr에 숫자 채워넣는다.
bool visited[MAX]={0,}; // 방문 여부를 체크한다.

void func(int cnt) {
    if (cnt == m) {
        for (int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        puts("");
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            visited[i]=true;
            arr[cnt]=i;
            func(cnt+1);
            visited[i]=false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    func(0);

    return 0;
}