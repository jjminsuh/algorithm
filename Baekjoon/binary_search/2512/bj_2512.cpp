#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

  int n = 0;
  long long inputTmp = 0;
  long long total = 0;
  vector<long long> input;
  long long answer = 0;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf(" %lld", &inputTmp);
    input.push_back(inputTmp);
  }

  scanf(" %lld", &total);

  sort(input.begin(), input.end());

  long long total_requested = accumulate(input.begin(), input.end(), 0);

  long long rest = total;

  int startIdx = 0;
  int endIdx = n - 1;
  int mid;

  long long equal_money = rest / n;
  
  while(equal_money >= input[startIdx]) {
    if(total_requested <= rest) {
      answer = input[input.size() - 1];
      printf("%lld", answer);

      return 0;
    }

    int start_search = startIdx;
    int end_search = endIdx;

    while(start_search <= end_search) {
      mid = (start_search + end_search) / 2;

      if(input[mid] <= equal_money) {
        start_search = mid + 1;
      } else {
        end_search = mid - 1;
      }
    }

    long long sum = 0;
    if(startIdx == mid) {
      sum = input[startIdx];
    } else {
      sum = accumulate(input.begin() + startIdx, input.begin() + start_search, 0);
    }
    
    rest = rest - sum;
    equal_money = rest / (input.size() - start_search);
    total_requested = accumulate(input.begin() + start_search, input.end(), 0);

    startIdx = start_search;
    endIdx = input.size() - 1;
  }

  answer = equal_money;

  printf("%lld", answer);

  return 0;
}

