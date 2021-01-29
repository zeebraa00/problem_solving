#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000000

using namespace std;

int prime[MAX+1]={0,}; // 0 => prime, 1 => composite

void eratosthenes() {
    for (int i=2; i*i<MAX; i++) {
        if (prime[i]==0) {
            for (int j=i*i; j<MAX; j+=i) {
                prime[j]=1;
            }
        }
    }
}

char p[100];
int k;

int main() {
    eratosthenes();
    scanf("%s %d", p, &k);

    for (int i=2; i<k; i++) {
        if (prime[i]==1) {
            continue;
        }
        int tmp=0;
        for (int j=0; p[j]; j++) {
            tmp=(tmp*10+(p[j]-'0'))%i;
        }
        if ( tmp==0 ) {
            printf("BAD %d\n",i);
            return 0;
        }
    }
    printf("GOOD\n");
    return 0;
}