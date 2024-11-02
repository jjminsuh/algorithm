#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  vector<int> numbers;
  int inputTmp = 0;

  for(int i = 0; i < n; i++) {
    scanf(" %d", &inputTmp);

    numbers.push_back(inputTmp);
  }

  int memo[10001] = { 0, };

  memo[1] = 1;

  for(int i = 2; i <= n; i++) {
    int max = 0;

    for(int j = 1; j <= i - 1; j++) {
      if(numbers[j - 1] < numbers[i - 1]) {
        if(max < memo[j] + 1) {
          max = memo[j] + 1;
        }
      } 
    }

    if(max == 0) {
      memo[i] = 1;
    } else {
      memo[i] = max;
    }
  }

  int answer = *max_element(memo, memo + n + 1);

  printf("%d", answer);

  return 0;
}