#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  scanf("%d", &n);

  long long input_tmp = 0;
  vector<long long> numbers;

  for(int i = 0; i < n; i++) {
    scanf(" %lld", &input_tmp);
    numbers.push_back(input_tmp);
  }

  sort(numbers.begin(), numbers.end());

  int answer = 0;

  for(int i = 0; i < numbers.size(); i++) {
    long long target = numbers[i];
    int left = 0;
    int right = numbers.size() - 1;

    while(left < right) {
      if(left == i) {
        left++;
        continue;
      }

      if(right == i) {
        right--;
        continue;
      }

      if(target == numbers[left] + numbers[right]) {
        answer++;
        break;
      } else if (target < numbers[left] + numbers[right]) {
        right--;
      } else {
        left++;
      }
    }
  }

  printf("%d", answer);

  return 0;
}