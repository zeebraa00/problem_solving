#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int arr[10000];
int len=0;
int n, pushNum;
char command[15];

void push(int pushNum) {
    arr[len]=pushNum;
    len++;
    return;
}

void pop() {
    if (len==0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[len-1]);
    len--;
    return;
}

void size() {
    printf("%d\n", len);
    return;
}

void empty() {
    if (len == 0) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return;
}

void top() {
    if (len == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[len-1]);
    return;
}

int main() {
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%s", command);
        if (!strcmp(command,"push")) {
            scanf("%d", &pushNum);
            push(pushNum);
        } else if (!strcmp(command,"pop")) {
            pop();
        } else if (!strcmp(command,"size")) {
            size();
        } else if (!strcmp(command,"empty")) {
            empty();
        } else if (!strcmp(command,"top")) {
            top();
        }
    }

    return 0;
}