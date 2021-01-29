#include <cstdio>
#include <iostream>
#define MAX 30

using namespace std;

int t,n,m;
int pascal[MAX+1][MAX+1];

void makePascal() {
    for (int i=2; i<=MAX; i++) {
        for (int j=1; j<i; j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
}

int main() {
    fill(&pascal[0][0], &pascal[MAX][MAX], 1);
    makePascal();

    scanf("%d", &t);

    for (int i=0; i<t; i++) {
        scanf("%d %d",&n, &m);
        printf("%d\n", pascal[m][n]);
    }

    return 0;
}