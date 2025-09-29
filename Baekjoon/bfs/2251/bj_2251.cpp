#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct bottles {
  int a;
  int b;
  int c;
};

int main() {

  // 입력 받기
  int a_max = 0;
  int b_max = 0;
  int c_max = 0;

  cin >> a_max >> b_max >> c_max;

  bottles initial;
  initial.a = 0;
  initial.b = 0;
  initial.c = c_max;

  // BFS로 모든 경우 탐색
  queue<bottles> to_visit;
  vector<vector<vector<bool> > > visited(a_max + 1, vector<vector<bool> >(b_max + 1, vector<bool>(c_max + 1, false)));
  set<int> answers;

  to_visit.push(initial);
  visited[initial.a][initial.b][initial.c];

  while(!to_visit.empty()) {
    bottles front = to_visit.front();
    to_visit.pop();

    // a가 비어 있으면 정답에 추가
    if(front.a == 0) {
      answers.insert(front.c);
    }

    bottles new_state;

    // a -> b
    new_state.c = front.c;

    if(front.a < b_max - front.b) {
      new_state.a = 0;
      new_state.b = front.b + front.a;
    } else {
      new_state.a = front.a - (b_max - front.b);
      new_state.b = b_max;
    }

    if(!visited[new_state.a][new_state.b][new_state.c]) {
      to_visit.push(new_state);
      visited[new_state.a][new_state.b][new_state.c] = true;
    }

    // a -> c
    new_state.b = front.b;

    if(front.a < c_max - front.c) {
      new_state.a = 0;
      new_state.c = front.c + front.a;
    } else {
      new_state.a = front.a - (c_max - front.c);
      new_state.c = c_max;
    }

    if(!visited[new_state.a][new_state.b][new_state.c]) {
      to_visit.push(new_state);
      visited[new_state.a][new_state.b][new_state.c] = true;
    }

    // b -> a
    new_state.c = front.c;

    if(front.b < a_max - front.a) {
      new_state.b = 0;
      new_state.a = front.a + front.b;
    } else {
      new_state.b = front.b - (a_max - front.a);
      new_state.a = a_max;
    }

    if(!visited[new_state.a][new_state.b][new_state.c]) {
      to_visit.push(new_state);
      visited[new_state.a][new_state.b][new_state.c] = true;
    }

    // b -> c
    new_state.a = front.a;

    if(front.b < c_max - front.c) {
      new_state.b = 0;
      new_state.c = front.c + front.b;
    } else {
      new_state.b = front.b - (c_max - front.c);
      new_state.c = c_max;
    }

    if(!visited[new_state.a][new_state.b][new_state.c]) {
      to_visit.push(new_state);
      visited[new_state.a][new_state.b][new_state.c] = true;
    }

    // c -> a
    new_state.b = front.b;

    if(front.c < a_max - front.a) {
      new_state.c = 0;
      new_state.a = front.a + front.c;
    } else {
      new_state.c = front.c - (a_max - front.a);
      new_state.a = a_max;
    }

    if(!visited[new_state.a][new_state.b][new_state.c]) {
      to_visit.push(new_state);
      visited[new_state.a][new_state.b][new_state.c] = true;
    }

    // c -> b
    new_state.a = front.a;

    if(front.c < b_max - front.b) {
      new_state.c = 0;
      new_state.b = front.b + front.c;
    } else {
      new_state.c = front.c - (b_max - front.b);
      new_state.b = b_max;
    }

    if(!visited[new_state.a][new_state.b][new_state.c]) {
      to_visit.push(new_state);
      visited[new_state.a][new_state.b][new_state.c] = true;
    }
  }

  for(auto ans: answers) {
    cout << ans << " ";
  }

  return 0;
}