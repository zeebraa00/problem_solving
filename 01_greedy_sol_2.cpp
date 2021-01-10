#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N,M,K;
    int sum;
    int buff;
    int first, second;
    vector<int> v;

    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        cin >> buff;
        v.push_back(buff);
    }

    sort(v.begin(), v.end(), greater<>());
    first = v[0];
    second = v[1];
    // for (auto iter=v.begin(); iter!=v.end(); ++iter) {
    //     cout << *iter; << endl;
    // }

    sum=((first*K)+second)*(M/(K+1))+(first*(M%(K+1)));

    printf("%d\n",sum);
    return 0;
}