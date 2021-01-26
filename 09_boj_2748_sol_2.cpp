#include <cstdio>
#include <iostream>

using namespace std;

long long fibo[100];
int n;

int main() {
    fibo[0]=0;
    fibo[1]=1;
    
    scanf("%d",&n);

    for (int i=2; i<=n; i++) {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }

    printf("%lld\n", fibo[n]);

    return 0;
}