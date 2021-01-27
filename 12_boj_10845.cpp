#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[10000];
int n, pushNum;
char command[15];
int first=0;
int len=0;

void push(int pushNum) {
    arr[len]=pushNum;
    len++;
    return;
}

void pop() {
    if (!(len-first)) {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[first]);
    first++;
    return;
}

void size() {
    printf("%d\n",len-first);
    return;
}

void empty() {
    if (!(len-first)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return;
}

void front() {
    if (!(len-first)) {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[first]);
    return;
}

void back() {
    if (!(len-first)) {
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
        // puts("");
        // printf("%s\n", command);
        // for (int j=0; j<len; j++) {
        //     printf("%d", arr[j]);
        // }
        // puts("");

        if (!strcmp(command, "push")) {
            scanf("%d", &pushNum);
            push(pushNum);
        } else if (!strcmp(command, "pop")) {
            pop();
        } else if (!strcmp(command, "size")) {
            size();
        } else if (!strcmp(command, "empty")) {
            empty();
        } else if (!strcmp(command, "front")) {
            front();
        } else if (!strcmp(command, "back")) {
            back();
        }
    }

    return 0;
}