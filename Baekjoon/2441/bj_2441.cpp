#include <iostream>

using namespace std;

int main() {

    int n = 0;

    scanf("%d", &n);

    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n; j++) {
            if(j < (n - i)) {
                printf(" ");
            } else {
                printf("*");
            }
        }

        printf("\n");
    }

    return 0;
}