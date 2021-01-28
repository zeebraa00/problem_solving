#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int isZero=0;
int sum=0;
vector<int> v;

int main() {
    while( scanf("%1d", &n) != EOF ) {
        // printf("input : %d\n",n);
        sum+=n;
        v.push_back(n);
        if ( n==0 ) {
            isZero=1;
        }
    }

    sort(v.begin(),v.end(),greater<>());

    if (sum%3==0 && isZero) {
        for (auto iter=v.begin(); iter!=v.end(); ++iter) {
            printf("%d",*iter);
        }
        puts("");
    } else {
        printf("-1\n");
    }

    return 0;
}