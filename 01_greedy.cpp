#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N,M,K;
    int buff;
    int sum=0;
    int count=0;
    vector<int> v;

    cin >> N >> M >> K;

    for (int i=0; i<N; i++) {
        cin >> buff;
        v.push_back(buff);
    }

    sort(v.begin(), v.end(), compare);

    // for (vector<int>::iterator itr = v.begin(); itr!=v.end(); ++itr) {
    //     cout << *itr << endl;
    // }

    while (true) {
        for (int i=0; i<K; i++) {
            sum += v[0];
            count++;
            if (count == M) {
                break;
            }
        }
        sum += v[1];
        count++;
        if (count == M) {
            break;
        }
    }

    printf("%d\n",sum);

    return 0;
}