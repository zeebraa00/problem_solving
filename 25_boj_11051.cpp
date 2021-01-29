#include <cstdio>
#include <iostream>
#define MAX 1000

using namespace std;

int n,k;
int fact[MAX+1]={0,};
int pascal[MAX+1][MAX+1];

void combination() {
    fill(&pascal[0][0], &pascal[MAX][MAX], 1);

    for (int i=2; i<=MAX; i++) {
        for (int j=1; j<i; j++) {
            pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j])%10007;
        }
    }
    // for (int i=0; i<MAX; i++) {
    //     for (int j=0; j<MAX; j++) {
    //         printf("%d ", pascal[i][j]);
    //     }
    //     puts("");
    // }
}

int main() {
    combination();

    scanf("%d %d", &n, &k);

    int result = pascal[n][k];
    printf("%d\n", result);

    return 0;
}