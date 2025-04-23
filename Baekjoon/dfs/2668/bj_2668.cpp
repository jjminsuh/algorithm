#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> NUMBERS;
set<int> RESULTS;

int VISITED[101];
bool IS_END = false;

void dfs(int root, int now_num) {
  // 이미 방문한 노드인 경우 멈춤
  if(VISITED[now_num] == 1) {

    // 멈췄을때 루프가 완성되는 경우 처리
    if(root == now_num) {
      IS_END = true;
    }

    return;
  }

  VISITED[now_num] = 1;

  dfs(root, NUMBERS[now_num - 1]);

  if(IS_END) { // 루프가 완성되는 경우 숫자 저장
    RESULTS.insert(now_num);
  }
}


int main() {
  int n = 0;

  cin >> n;

  int input = 0;

  for(int i = 0; i < n; i++) {
    cin >> input;
    NUMBERS.push_back(input);
  }

  // dfs를 통해 루프를 감지
  for(int i = 1; i <= n; i++) {
    dfs(i, i);

    for(int j = 0; j <= n; j++) {
      VISITED[j] = 0;
    }

    IS_END = false;
  }

  cout << RESULTS.size() << "\n";

  for(auto num: RESULTS) {
    cout << num << "\n";
  }

  return 0;
}
