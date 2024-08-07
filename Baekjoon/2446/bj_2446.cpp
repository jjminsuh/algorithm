#include <iostream>

using namespace std;

int main() {

    int n = 0;

    scanf("%d", &n);

    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < (2 * n) - 1; j++) {
            if(j < (((2 * n) - 1) - ((2 * i) - 1)) / 2) {
                printf(" ");
            } else if (((2 * n) - 1) - j <= (((2 * n) - 1) - ((2 * i) - 1)) / 2) {
                continue;
            } else {
                printf("*");
            }
        }

        printf(" \n");
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < (2 * n) - 1; j++) {
            if(j < (((2 * n) - 1) - ((2 * i) - 1)) / 2) {
                printf(" ");
            } else if (((2 * n) - 1) - j <= (((2 * n) - 1) - ((2 * i) - 1)) / 2) {
                continue;
            } else {
                printf("*");
            }
        }

        printf(" \n");
    }

    return 0;
}