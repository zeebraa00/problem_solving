#include <cstdio>
#include <iostream>
#define MAX 1000000

using namespace std;

int parent[MAX+1]={0,};
int n,m;
int cmd,a,b;

int getParent(int x) {
    if (parent[x]==x) {
        return x;
    }
    int parents = getParent(parent[x]);
    parent[x]=parents;
    return parents;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i=1; i<=n; i++) {
        parent[i]=i;
    }

    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &cmd, &a, &b);

        if (cmd == 0) {
            int parentX = getParent(a);
            int parentY = getParent(b);
            parent[parentY] = parentX;
        } else {
            if (getParent(a) == getParent(b)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }   
    }
    return 0;
}