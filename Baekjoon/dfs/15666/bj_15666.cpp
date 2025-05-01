#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

set<deque<int> > results;

// 중복 조합 구하기
void dfs(int depth, int n, int m, vector<int> numbers, deque<int> result, int idx) {
  if(result.size() == m) {
    sort(result.begin(), result.end());
    results.insert(result);

    return;
  }

  int last_used = -1;

  for(int i = idx; i < n; i++) {
    // 같은 depth에서 같은 숫자 이용하지 않도록
    if(last_used == numbers[i]) {
      continue;
    }

    result.push_back(numbers[i]);
    dfs(depth + 1, n, m, numbers, result, i);
    result.pop_back();

    last_used = numbers[i];
  }
}

int main() {

  int n = 0;
  int m = 0;

  cin >> n >> m;

  vector<int> numbers(n, 0);

  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  sort(numbers.begin(), numbers.end());

  deque<int> result;

  dfs(0, n, m, numbers, result, 0);

  for(auto result: results) {
    for(int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }

    cout << "\n";
  }

  return 0;
}