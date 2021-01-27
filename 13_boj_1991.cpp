#include <cstdio>
#include <iostream>
#define MAX 27

using namespace std;

typedef struct Node{
    char data;
    char left;
    char right;
}node;

node arr[MAX];
int n;
char a,b,c;

void preorder(char c) {
    if (c=='.') {
        return;
    }
    printf("%c", c);
    preorder(arr[c-'A'].left);
    preorder(arr[c-'A'].right);
}

void inorder(char c) {
    if (c=='.') {
        return;
    }
    inorder(arr[c-'A'].left);
    printf("%c", c);
    inorder(arr[c-'A'].right);
}

void postorder(char c) {
    if (c=='.') {
        return;
    }
    postorder(arr[c-'A'].left);
    postorder(arr[c-'A'].right);
    printf("%c", c);
}

int main() {
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf(" %c %c %c", &a, &b, &c);

        arr[a-'A'].data=a;
        arr[a-'A'].left=b;
        arr[a-'A'].right=c;
    }

    preorder('A');
    puts("");
    inorder('A');
    puts("");
    postorder('A');
    puts("");

    return 0;
}