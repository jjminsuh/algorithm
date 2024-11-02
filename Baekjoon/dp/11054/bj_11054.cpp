#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int inputTmp = 0;
  vector<int> input;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf(" %d", &inputTmp);
    input.push_back(inputTmp);
  }

  // i가 마지막 원소인 증가수열 구하기
  int memoIncrease[1000] = {0, };
  memoIncrease[0] = 1;

  for(int i = 1; i < n; i++) {
    int max = 0;

    for(int j = 0; j <= i - 1; j++) {
      if(input[j] >= input[i]) {
        continue;
      }

      if(max < memoIncrease[j] + 1) {
        max = memoIncrease[j] + 1;
      }
    }

    if(max == 0) {
      memoIncrease[i] = 1;
    } else {
      memoIncrease[i] = max;
    }
  }

  // i가 첫번째 원소인 증가수열 구하기
  int memoDecrease[1000] = {0, };
  memoDecrease[n - 1] = 1;

  for(int i = n - 2; i >= 0; i--) {
    int max = 0;

    for(int j = i + 1; j < n; j++) {
      if(input[i] <= input[j]) {
        continue;
      }

      if(max < memoDecrease[j] + 1) {
        max = memoDecrease[j] + 1;
      }
    }

    if(max == 0) {
      memoDecrease[i] = 1;
    } else {
      memoDecrease[i] = max;
    }
  }

  // 바이토닉 수열 최댓값
  vector<int> bitonic;

  for(int i = 0; i < n; i++) {
    bitonic.push_back(memoIncrease[i] + memoDecrease[i] - 1);
  }

  int answer = 0;

  answer = *max_element(bitonic.begin(), bitonic.end());

  printf("%d", answer);

  return 0;
}