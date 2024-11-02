#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  int s = 0;

  scanf("%d %d", &n, &s);

  vector<int> input;
  int input_tmp = 0;

  for(int i = 0; i < n; i++) {
    scanf(" %d", &input_tmp);
    input.push_back(input_tmp);
  }

  queue<int> numbers;
  int sum = 0;
  int min_count = -1;

  int iter = 0;

  while(iter <= input.size()) {
    if(sum < s) {
      if(iter >= input.size()) {
        break;
      }
      
      numbers.push(input[iter]);
      sum += input[iter];
      iter++;
    } else {
      if(min_count == -1 || min_count > numbers.size()) {
        min_count = numbers.size();
      }

      sum -= numbers.front();
      numbers.pop();
    }
  }

  if(min_count == -1) {
    min_count = 0;
  }

  printf("%d", min_count);

  return 0;
}