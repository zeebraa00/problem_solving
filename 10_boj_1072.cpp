#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long x,y,z;
long long nz;
int idx=0;

long long high=1000000000;
long long low=0;
int mid;
int result=-1;

int main() {
    scanf("%lld %lld", &x, &y);
    z = (100*y)/x;
    // printf("initial z : %lld\n", z);

    if ( z >= 99 ) { // z값 바뀌지 않는 조건
        printf("-1\n");
        return 0;
    }

    while (low <= high) {
        mid = (high + low) / 2;
        long long nx = x + mid;
        long long ny = y + mid;
        nz = (100 * ny) / nx;
        // printf("high : %lld, low : %lld \n\n", high, low);
        // printf("z : %lld, nz : %lld \n\n", z, nz);
        if (nz > z) {
            high = mid-1;
        } else {
            low = mid+1;
            result = mid + 1;
        }
    }
    printf("%d\n", result);

    return 0;
}