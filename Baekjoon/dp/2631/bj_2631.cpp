#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;

  cin >> n;

  vector<int> line(n, 0);  

  for(int i = 0; i < n; i++) {
    cin >> line[i];
  }

  // 가장 긴 증가하는 부분 수열 구하기
  vector<int> memo(n + 1, 0);

  memo[1] = 1;

  for(int i = 2; i <= n; i++) {
    int max = 0;

    for(int j = 1; j <= i - 1; j++) {
      if(line[j - 1] < line[i - 1]) {
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

  int max_length = *max_element(memo.begin(), memo.end() + 1);

  // 전체 길이에서 가장 긴 증가하는 부분 수열의 길이를 뺀 나머지 학생들이 모두 움직여야 함
  int answer = n - max_length;

  cout << answer;

  return 0;
}