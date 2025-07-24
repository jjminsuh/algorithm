#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int n = 0;
  int m = 0;

  cin >> n >> m;

  vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));

  vector<set<int> > party;

  int know_num = 0;
  set<int> know_people;
  set<int> hear_true;

  cin >> know_num;

  for(int i = 0; i < know_num; i++) {
    int tmp = 0;
    cin >> tmp;
    know_people.insert(tmp);
  }

  int answer = 0;

  for(int i = 0; i < m; i++) {
    int num = 0;
    cin >> num;

    set<int> heard;

    for(int j = 0; j < num; j++) {
      int tmp = 0;
      cin >> tmp;

      heard.insert(tmp);
    }

    // 인접행렬 저장
    for(int start: heard) {
      for(int end: heard) {
        if(start != end) {
          graph[start][end] = 1;
          graph[end][start] = 1;
        }
      }
    }

    party.push_back(heard);
  }

  // bfs로 진실을 들어야하는 사람들 모두 탐색
  for(int root: know_people) {
    queue<int> to_visit;

    to_visit.push(root);
    hear_true.insert(root);

    while(!to_visit.empty()) {
      int front = to_visit.front();
      to_visit.pop();

      for(int i = 1; i <= n; i++) {
        if(graph[front][i] == 1 && (hear_true.find(i) == hear_true.end())) {
          to_visit.push(i);
          hear_true.insert(i);
        }
      }
    }
  }

  // 파티 순회하며 진실을 들어야하는 사람이 없는 경우 찾기
  for(int i = 0; i < m; i++) {
    bool say_true = false;

    for(int person: party[i]) {
      if(hear_true.find(person) != hear_true.end()) {
        say_true = true;
        break;
      }
    }

    if(!say_true) {
      answer++;
    }
  }

  cout << answer;
}