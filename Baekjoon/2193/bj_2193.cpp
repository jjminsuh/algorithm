#include <iostream>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  long long memo[91][2] = {0, };

  memo[1][0] = 0;
  memo[1][1] = 1;

  for(int i = 2; i <= n; i++) {
    memo[i][0] = memo[i - 1][0] + memo[i - 1][1];
    memo[i][1] = memo[i - 1][0];
  }

  long long answer = 0;

  answer = memo[n][0] + memo[n][1];

  printf("%llu", answer);

}