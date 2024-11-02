#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int x = 0;

  int inputTmp = 0;
  vector<int> input;

  scanf("%d %d", &n, &x);

  for(int i = 0; i < n; i++) {
    scanf(" %d", &inputTmp);
    input.push_back(inputTmp);
  }

  int sum = 0;

  for(int j = 0; j < x; j++) {
    sum = sum + input[j];
  }

  int maxNum = sum;
  int cnt = 1;

  for(int i = 0; i <= n - x; i++) {
    if(i != 0) {
      sum = sum - input[i - 1] + input[i + x - 1];

        if(sum > maxNum) {
        maxNum = sum;
        cnt = 1;
      } else if(sum == maxNum) {
        cnt = cnt + 1;
      }
    }
  }

  if(maxNum == 0) {
    printf("SAD");
  } else {
    printf("%d\n%d", maxNum, cnt);
  }

  return 0;
}