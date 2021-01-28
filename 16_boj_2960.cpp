#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
int cnt=0;
int arr[1000]={0,}; // 에라토스테네스의 체에 걸러지면 1로 변경
int prime=2;
int iter;

int main() {
    scanf("%d %d", &n, &k);

    while(true) {
        int saved = prime;
        for (;prime<=n;prime+=saved) {
            // printf("%d\n",prime);
            if (arr[prime-1] != 1) {
                arr[prime-1]=1;
                cnt++;
                if (cnt==k) {
                    printf("%d\n", prime);
                    return 0;
                }
            }
            // for (int i=0; i<n; i++) {
            //     printf("%d ", arr[i]);
            // }
            // puts("");
        }
        for (int i=1; i<n; i++) {
            if (arr[i] == 0) {
                prime = i+1;
                // printf("새로운 소수 : %d\n", prime);
                break;
            }
        }
    }

    return 0;
}