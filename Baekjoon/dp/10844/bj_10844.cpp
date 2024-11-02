#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n = 0;

    scanf("%d", &n);

    long long memo[101][10] = {0, };

    for(int j = 1; j <= 9; j++) {
        memo[1][j] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j<= 9; j++) {
            if(j == 0) {
                memo[i][j] = memo[i - 1][j + 1] % 1000000000;
            } else if(j == 9) {
                memo[i][j] = memo[i - 1][j - 1] % 1000000000;
            } else {
                memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    long long answer = 0;

    for(int j = 0; j <= 9; j++) {
        answer = (answer + memo[n][j]) % 1000000000;
    }

    printf("%llu", answer);

    return 0;
}