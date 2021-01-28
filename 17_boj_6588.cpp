#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000

using namespace std;

int n;
int a,b;

int arr[MAX+1]={0,}; // 0 => prime, 1 => composite
int prime=2;
int saved;

void eratosthenes() {
    for (int i=2; i*i<=MAX; i++) {
        if (arr[i] == 0) {
            for (int j = i*i; j<=MAX; j+=i) {
                arr[j]=1;
            }
        }
    }
}

int main() {
    eratosthenes();
    // for (int i=0; i<=MAX; i++) {
    //     printf("%d ", arr[i]);
    // }

    n=-1;
    while ( n != 0 ) {
        scanf("%d", &n);
        for (int i=2; i<n; i++) {
            if ( arr[i]==0 && arr[n-i]==0 ) {
                printf("%d = %d + %d\n", n,i,n-i);
                break;
            }
        }
    }

    return 0;
}