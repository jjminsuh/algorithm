#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int n = 0;
  int input_tmp = 0;
  int MAX = 1000000000;
  priority_queue<int> numbers;

  scanf("%d", &n);

  for(int i = 0; i < n * n; i++) {
    scanf(" %d", &input_tmp);

    if(numbers.size() < n) {
      numbers.push(MAX - input_tmp);
      continue;
    }

    if(numbers.top() > MAX - input_tmp) {
      numbers.pop();
      numbers.push(MAX - input_tmp);
    }
  }

  printf("%d", MAX - numbers.top());

  return 0;
}