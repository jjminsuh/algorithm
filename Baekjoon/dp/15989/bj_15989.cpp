#include <iostream>
#include <vector>

using namespace std;

int main() {

  int t = 0;

  cin >> t;

  for(int i = 0; i < t; i++) {
    int n = 0;

    cin >> n;
    
    // 무조건 오름차순으로 덧셈이 되도록 해서 중복을 처리할 수 있게 함
    // [i][j] -> j로 끝나는 덧셈, 합은 i
    int memo[10001][3] = { 0, };

    memo[1][0] = 1;
    
    memo[2][0] = 1;
    memo[2][1] = 1;

    memo[3][0] = memo[2][0];
    memo[3][1] = memo[1][0];
    memo[3][2] = 1;

    for(int j = 4; j <= n; j++) {
      memo[j][0] = memo[j - 1][0];
      memo[j][1] = memo[j - 2][0] + memo[j - 2][1];
      memo[j][2] = memo[j - 3][0] + memo[j - 3][1] + memo[j - 3][2];
    }

    cout << memo[n][0] + memo[n][1] + memo[n][2] << "\n";
  }

  return 0;
}
