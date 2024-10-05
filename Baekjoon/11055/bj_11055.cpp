#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  vector<int> input;
  int tmp = 0;

  for(int i = 0; i < n; i++) {
    scanf(" %d", &tmp);
    input.push_back(tmp);
  }

  // i번째 값으로 끝나는 합이 가장 큰 증가하는 수열
  int memo[1001] = { 0, };

  memo[0] = input[0];

  for(int i = 1; i < n; i++) {
    int max = 0;

    for(int j = i; j >= 0; j--) {
      if(input[j] < input[i]) {
        if(max < memo[j] + input[i]) {
          max = memo[j] + input[i];
        }
      }
    }

    if(max == 0) {
      memo[i] = input[i];
    } else {
      memo[i] = max;
    }
  }

  int answer = 0;

  answer = *max_element(memo, memo + n);

  printf("%d", answer);

  return 0;
}