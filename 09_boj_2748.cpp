#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> fiboNum;
int n;

long long fibo(int n) {
    long long result=1;
    for (int i=2; i<=n; i++) {
        // for (int k=0; k<i; k++) {
        //     printf("%d ", fiboNum[k]);
        // }
        // puts("");
        result = fiboNum[i-2] + result; // memoization
        // printf("result : %d \n", result);
        // fiboNum[i] = result;
        fiboNum.push_back(result);
    }
    return result;
}

int main() {
    scanf("%d",&n);

    if (n==0) {
        printf("%d\n", 0);
        return 0;
    } else if (n==1) {
        printf("%d\n", 1);
        return 0;
    }

    fiboNum.push_back(0);
    fiboNum.push_back(1);

    printf("%lld\n",fibo(n));

    // for (int k=0; k<=n; k++) {
    //     printf("%lld ", fiboNum[k]);
    // }
    // puts("");

    return 0;
}