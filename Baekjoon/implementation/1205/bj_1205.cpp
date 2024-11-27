#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_desc(int a, int b) {
  return a > b;
}

int main() {

  int n = 0;
  int score = 0;
  int p = 0;

  int input_tmp = 0;
  vector<int> input;

  scanf("%d %d %d", &n, &score, &p);

  if(n == 0) {
    if(p >= 1) {
      printf("%d", 1);
      return 0;
    }
  }

  for(int i = 0; i < n; i++) {
    scanf(" %d", &input_tmp);

    input.push_back(input_tmp);
  }

  sort(input.begin(), input.end(), compare_desc);

  if(n >= p) {
    if(score <= input[n - 1]) {
      printf("%d", -1);
    } else {
      for(int i = 0; i < n; i++) {
        if(score >= input[i]) {
          printf("%d", i + 1);
          break;
        } 
      }
    }
  } else {
    if(score < input[n - 1]) {
      printf("%d", n + 1);
    } else {
      for(int i = 0; i < n; i++) {
        if(score >= input[i]) {
          printf("%d", i + 1);
          break;
        } 
      }
    }
  }

  return 0;
}