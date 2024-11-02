#include <iostream>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  int memo[10001][10] = {0, };

  for(int j = 0; j < 10; j++) {
    memo[1][j] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < 10; j++) {
      if(j == 0) {
        memo[i][j] = memo[i - 1][j] % 10007;
      } else {
        memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 10007;
      }
    }
  }

  int answer = 0;

  for(int j = 0; j < 10; j++) {
    answer = (answer + memo[n][j]) % 10007;
  }

  printf("%d", answer);

}