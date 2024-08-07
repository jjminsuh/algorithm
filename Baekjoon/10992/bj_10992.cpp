#include <iostream>

using namespace std;

int main() {

    int n = 0;

    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++) {
            printf(" ");
    }

    printf("* \n");

    if(n != 1) {
        for(int i = 2; i <= n - 1; i++) {
            for(int j = 0; j < n - i; j++) {
                printf(" ");
            }

            printf("*");

            for(int j = 0; j < (2 * i) - 3; j++) {
                printf(" ");
            }

            printf("* \n");
        }

        for(int i = 0; i < (2 * n) - 1; i++) {
            printf("*");
        }
    }

    return 0;
}