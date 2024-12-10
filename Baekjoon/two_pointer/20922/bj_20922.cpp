#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  int k = 0;

  cin >> n >> k;

  vector<int> input;
  int input_tmp = 0;

  for(int i = 0; i < n; i++) {
    cin >> input_tmp;

    input.push_back(input_tmp);
  }


  unordered_map<int, int> numbers;
  int cnt = 0;

  int start = 0;
  int end = 0;
  int max = 0;
  numbers.insert(make_pair(input[end], 1));
  end++;

  while(end < n) {
    if(numbers.find(input[end]) != numbers.end()) {
      if(numbers[input[end]] < k) {
        numbers[input[end]]++;
        end++;
      } else {
        while(start < end) {
          if(numbers[input[start]] == 1) {
            numbers.erase(input[start]);
          } else {
            numbers[input[start]]--;
          }
          
          if(input[start] == input[end]) {
            start++;
            break;
          }

          start++;
        }
      }
    } else {
      numbers.insert(make_pair(input[end], 1));
      end++;
    }

    if(max < end - start) {
      max = end - start;
    }
  }

  cout << max;

  return 0;
}