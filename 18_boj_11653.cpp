#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000000

using namespace std;

int arr[MAX+1]={0,}; // 0 => prime, 1 => composite

void eratosthenes() {
    for (int i=2; i*i<=MAX; i++) {
        if( arr[i]==0 ) {
            for (int j=i*i; j<=MAX; j+=i) {
                arr[j]=1;
            }
        }
    }
}

int n;

int main() {
    eratosthenes();
    // for (int i=0; i<=MAX; i++) {
    //     printf("%d ", arr[i]);
    // }

    scanf("%d", &n);

    int iter=n;
    for (int i=2; i<=iter; i++) {
        if (arr[i]==1) {
            continue;
        }
        while (n%i == 0) {
            printf("%d\n",i);
            n=n/i;
        }
        if (n==1) {
            break;
        }
    }

    return 0;
}