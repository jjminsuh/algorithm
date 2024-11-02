#include <string>

int main() {

    int n = 0;
    char number = '0';

    int sum = 0;

    scanf("%d ", &n);

    for(int i = 0; i < n; i++) {
        scanf("%c", &number);

        sum = sum + (number - '0');
    }

    printf("%d", sum);

    return 0;
}