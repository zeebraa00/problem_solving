#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a,b,c,d;

int GCD(int x, int y) {
    return y ? GCD(y, x%y) : x;
}

int LCM(int x, int y) {
    return (x*y)/GCD(x,y);
}

int n1, n2, gcd;

int main() {
    while ( scanf("%d %d %d %d", &a, &b, &c, &d) != EOF ) {
        n1 = LCM(b,d);
        n2 = a*(n1/b) + c*(n1/d);
        gcd = GCD(n1,n2);
        n1 = n1 / gcd;
        n2 = n2 / gcd;
        printf("%d %d\n", n2, n1);
    }

    return 0;
}