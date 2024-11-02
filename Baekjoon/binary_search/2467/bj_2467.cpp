#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {

  int n = 0;
  int input_tmp = 0;
  vector<int> input;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf(" %d", &input_tmp);

    input.push_back(input_tmp);
  }

  int result_first = 0;
  int result_second = 1;
  int min = input[result_first] + input[result_second];

  for(int i = 0; i < n - 1; i++) {
    int start = i + 1;
    int end = n - 1;

    while(start <= end) {
      int mid = (start + end) / 2;

      if(abs(min) > abs(input[i] + input[mid])) {
        min = input[i] + input[mid];
        result_first = i;
        result_second = mid;
      }

      if(input[i] + input[mid] < 0) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  printf("%d %d", input[result_first], input[result_second]);

  return 0;
}