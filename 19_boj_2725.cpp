#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

int c,n;
int cnt=1;
int arr[MAX][MAX]={0,};
int gcdArray[MAX+1][MAX+1]={0,};

int GCD(int a, int b) { // using dynamic programming
    if (b) {
        if (gcdArray[b][a%b]==0)
            return GCD(b, a%b);
        else
            return gcdArray[b][a%b];
    } else {
        return a;
    }
}

int main() {
    scanf("%d", &c);

    for (int i=1; i<=MAX; i++) {
        for (int j=1; j<=MAX; j++) {
            gcdArray[i][j]=GCD(i,j);
        }
    }

    for (int i=0; i<c; i++) {
        scanf("%d", &n);
        for (int x=1; x<=n; x++) {
            for (int y=1; y<=n-x; y++) {
                int gcd = gcdArray[x][y];
                // printf("x : %d, y : %d, gcd : %d\n",x,y,gcd);
                int nx=x/gcd;
                int ny=y/gcd;
                if ( arr[nx][ny] == 0 ) {
                    // printf("개이득 x : %d, y : %d, gcd : %d\n",x,y,gcd);
                    arr[nx][ny]=1;
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt*2+1);
    }
 
    return 0;
}