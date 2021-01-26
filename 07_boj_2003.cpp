#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;
int cnt=0;

int main() {
    scanf("%d %d", &n, &m);

    int buff;
    for (int i=0; i<n; i++) {
        scanf("%d", &buff);
        v.push_back(buff);
    }

    for (int i=0; i<n; i++) {
        int remain = m;
        for ( int j=i; j<n; j++ ) {
            remain = remain - v[j];
            // printf("v[i] : %d\n", v[j]);
            // printf("index : %d\n", j);
            // printf("remaining : %d\n", remain);
            if ( remain < 0 ) {
                break;
            }
            if ( remain == 0 ) {
                cnt++;
                // printf("done ! - %d\n", cnt);
                break;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}