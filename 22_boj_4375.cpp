#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long one;
long long len;

int memo[10000]={0,};

int main() {
    while( scanf("%lld",&n) != EOF ) {
        one=1;
        len=1;
        while (true) {
            if (memo[n]!=0) {
                printf("%d\n", memo[n]);
                break; 
            } else {
                if (one%n==0) {
                    printf("%lld\n", len);
                    memo[n]=len;
                    break;
                } else {
                    len++;
                    one=(one*10+1)%n;
                    // printf("one : %lld\n\n", one);
                }
            }
        }
    }
    return 0;
}