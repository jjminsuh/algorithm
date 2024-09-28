#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  int inputTmp = 0;
  vector<int> wineAmount;

  for(int i = 0; i < n; i++) {
    scanf("%d", &inputTmp);

    wineAmount.push_back(inputTmp);
  }

  int memo[10001][2] = {0, };

  memo[1][0] = wineAmount[0];
  memo[2][0] = wineAmount[1];
  memo[2][1] = memo[1][0] + wineAmount[1];

  for(int i = 3; i <= n; i++) {
    memo[i][0] = max(max(memo[i - 2][0] + wineAmount[i - 1],
                      memo[i - 2][1] + wineAmount[i - 1]),
                      max(memo[i - 3][0] + wineAmount[i - 1],
                          memo[i - 3][1] + wineAmount[i - 1]));
    memo[i][1] = memo[i - 1][0] + wineAmount[i - 1];
  }

  int answer = 0;

  answer = max(memo[n][0], max(memo[n][1], memo[n - 1][1]));

  printf("%d", answer);

  return 0;
}