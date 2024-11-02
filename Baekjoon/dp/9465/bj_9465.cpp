#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int t = 0;
  int n = 0;
  int inputTmp = 0;
  vector <int> inputTmpVector;

  vector< vector <int> > stickerPoint;

  scanf("%d", &t);

  for(int i = 0; i < t; i++) {

    scanf("%d", &n);

    for(int row = 0; row < 2; row++) {
      for(int col = 0; col < n; col++) {
        scanf(" %d", &inputTmp);

        inputTmpVector.push_back(inputTmp);
      }

      stickerPoint.push_back(inputTmpVector);
      inputTmpVector.clear();
    }

    int memo[100001][2] = {0, };

    memo[1][0] = stickerPoint[0][0];
    memo[1][1] = stickerPoint[1][0];

    for(int j = 2; j <= n; j++) {
      memo[j][0] = max(max(memo[j - 1][1] + stickerPoint[0][j - 1], 
                            memo[j - 2][0] + stickerPoint[0][j - 1]), 
                        memo[j - 2][1] + stickerPoint[0][j - 1]);
      memo[j][1] = max(max(memo[j - 1][0] + stickerPoint[1][j - 1], 
                            memo[j - 2][1] + stickerPoint[1][j - 1]),
                        memo[j - 2][0] + stickerPoint[1][j - 1]);
    }

    int answer = max(memo[n][0], memo[n][1]);

    printf("%d\n", answer);

    stickerPoint.clear();
  }

  return 0;
}