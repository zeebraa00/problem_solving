#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long m;
long long result;
vector<long long> v;

int main() {
    scanf("%d %lld", &n, &m);

    long long buff;

    for (int i=0; i<n; i++) {
        scanf("%lld", &buff);
        v.push_back(buff);
    }

    sort(v.begin(), v.end(), greater<>());

    // for (auto iter=v.begin(); iter != v.end(); ++iter) {
    //     printf("%lld\n", *iter);
    // }

    long long highest = v[0];
    long long lowest = 0; // 나무를 다 잘라야 하는 경우가 있을 수 있으므로
  
    while ( lowest <= highest ) {
        long long mid = (highest + lowest) / 2;
        long long get = 0;

        for (int i=0; i<n; i++) {
            if ( v[i] > mid ) {
                get += (v[i]-mid);
            }
        }

        if ( get >= m ) {
            if ( result < mid ) {
                result = mid;
            }
            lowest = mid + 1;
        } else {
            highest = mid - 1;
        }
    }

    // for (auto iter=v.begin(); iter != v.end(); ++iter) {
    //     printf("%d\n", *iter);
    // }

    printf("%lld\n", result);

    return 0;
}