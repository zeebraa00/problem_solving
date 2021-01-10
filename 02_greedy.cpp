#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int array[100][100]={0,};
    int n,m;
    int buff;
    vector<int> min;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        min.push_back(MAX);
        for (int j=0; j<m; j++) {
            cin >> buff;
            array[i][j] = buff;
            if (min[i]>buff) {
                min[i]=buff;
            }
        }
    }

    sort(min.begin(),min.end(), greater<>());
    printf("%d\n",min[0]);
    return 0;
}