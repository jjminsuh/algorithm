#include <iostream>
#include <vector>

using namespace std;

// 0 ~ 9까지 비트로 표현한 배열 저장 (아래 모양 인덱스 맞춰서 저장)
//  0
// 1 2
//  3
// 4 5
//  6
vector<vector<bool>> NUMBERS = {
  {1, 1, 1, 0, 1, 1, 1}, // 0
  {0, 0, 1, 0, 0, 1, 0}, // 1
  {1, 0, 1, 1, 1, 0, 1}, // 2
  {1, 0, 1, 1, 0, 1, 1}, // 3
  {0, 1, 1, 1, 0, 1, 0}, // 4
  {1, 1, 0, 1, 0, 1, 1}, // 5
  {1, 1, 0, 1, 1, 1, 1}, // 6
  {1, 0, 1, 0, 0, 1, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

bool can_change(int n, int k, int p, int x, int target) {

  // 반전 시켜야 하는 불의 개수
  int cnt = 0;

  // 자릿수별로 분리해서 확인
  for(int i = 0; i < k; i++) {
    int now = x % 10;
    int to_change = target % 10;

    for(int j = 0; j < 7; j++) {
      if(NUMBERS[now][j] ^ NUMBERS[to_change][j]) {
        cnt++;
      }
    }

    x = x / 10;
    target = target / 10;
  }


  if(cnt <= p) {
    return true;
  }

  return false;
}

int main() {

  int n = 0;
  int x = 0;
  int k = 0;
  int p = 0;

  cin >> n >> k >> p >> x;

  int answer = 0;

  // 모든 숫자로 바꾸는 것이 가능한지 확인
  for(int i = 1; i <= n; i++) {
    // 현재 층인 경우 건너뛰기
    if(i == x) {
      continue;
    }

    if(can_change(n, k, p, x, i)) {
      answer++;
    }
  }

  cout << answer;

  return 0;
}