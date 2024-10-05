#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  vector<int> input;
  int tmp = 0;

  for(int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    input.push_back(tmp);
  }

  int memo[1001] = { 0, };

  for(int i = 0; i < n; i++) {
    int max = 0;

    for(int j = i; j >= 0; j--) {
      if(input[j] > input[i]) {
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

  int answer = 0;

  answer = *max_element(memo, memo + n);

  printf("%d", answer);

  return 0;
}