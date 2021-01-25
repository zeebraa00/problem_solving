#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> v1; // 후보 숫자
vector<int> v2; // 추천 횟수

int main () {
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i=0; i<m; i++) {
        int buff;
        scanf("%d", &buff);
        if (i==0) {
            v1.push_back(buff);
            v2.push_back(1);
            continue;
        }
        
        auto isExist = find(v1.begin(), v1.end(), buff);
        if (isExist != v1.end()) {
            // exists
            for (int j=0; j<v1.size(); j++) {
                if (v1[j]==buff) {
                    v2[j]++;
                }
            }
        } else {
            // not exists
            if (v1.size() == n) {
                int eraser=0;
                int min = v2[0];
                for (int j=0; j<n; j++) {
                    if (min > v2[j]) {
                        eraser=j;
                        min=v2[j];
                    }
                }
                v1.erase(v1.begin() + eraser);
                v2.erase(v2.begin() + eraser);
            }
            v1.push_back(buff);
            v2.push_back(1);
        }
    }
    sort(v1.begin(), v1.end());
    for (auto iter=v1.begin(); iter != v1.end(); ++iter) {
        printf("%d ", *iter);
    }
    // for (auto iter=v2.begin(); iter != v2.end(); ++iter) {
    //     printf("%d ", *iter);
    // }

    return 0;
}

/*
3
9
2 1 4 3 5 6 2 7 2
*/