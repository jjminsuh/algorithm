#include <iostream>
#include <cstdio>

long fact(int n) {
    if(n == 0) {
        return 1;
    }
    
    return n*fact(n-1);
}

int main() {

    int n = 0;
    long ans = 0;

    scanf("%d", &n);

    ans = fact(n);

    printf("%ld", ans);

    return 0;
}