#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 500

using namespace std;

int triangle[MAX][MAX]={0,};
int n;
vector<int> v;

int main() {
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            if (j==0) {
                triangle[i][j] += triangle[i-1][j];
            } else if (j==i) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += max(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
    }

    for (int i=0; i<n; i++) {
        v.push_back(triangle[n-1][i]);
    }

    sort(v.begin(), v.end(), greater<>());
    printf("%d\n", v[0]);

    return 0;
}