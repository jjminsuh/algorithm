#include <iostream>

using namespace std;

int main() {

    int n = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            if(j < n - i) {
                printf(" ");
            } else {
                printf("*");
            }
        }

        printf(" \n");
    }

    for(int i = n - 1; i >= 1; i--) {
        for(int j = 0; j < n; j++) {
            if(j < n - i) {
                printf(" ");
            } else {
                printf("*");
            }
        }

        printf(" \n");
    }

    return 0;
}