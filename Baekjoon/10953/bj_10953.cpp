#include <iostream>

using namespace std;

int main() {

    int t = 0;
    int a = 0;
    int b = 0;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf(" %d, %d", &a, &b);

        printf("%d\n", a + b);
    }

    return 0;
}
