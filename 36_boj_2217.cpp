#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> v;
    vector<int> ans;

    scanf("%d", &n);

    int tmp;
    for (int i=0; i<n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(),v.end());

    int answer;
    for (int i=0; i<n; i++) {
        answer = v[i]*(n-i);
        ans.push_back(answer);
    }

    sort(ans.begin(),ans.end(), greater<int>());

    printf("%d\n", ans[0]);

    return 0;
}