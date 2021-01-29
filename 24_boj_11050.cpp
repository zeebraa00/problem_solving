#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
int fact[11]={0,};

int factorial(int x) {
    if ( fact[x] != 0 ) {
        return fact[x];
    }
    if (x==1 || x==0) {
        fact[x]=1;
        return 1;
    }
    fact[x]=x*factorial(x-1);
    return fact[x];
}

int main() {
    scanf("%d %d",&n, &k);

    int result = factorial(n)/(factorial(k)*factorial(n-k));
    printf("%d\n",result);

    return 0;
}