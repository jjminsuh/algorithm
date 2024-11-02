#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  int m = 0;

  scanf("%d", &m);

  int input_tmp = 0;
  vector<int> row_tmp;
  vector<vector<int> > map;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf(" %d", &input_tmp);
      row_tmp.push_back(input_tmp);
    }

    map.push_back(row_tmp);
    row_tmp.clear();
  }

  bool flag = false;
  int start = 0;
  int next = 0;
  vector<int> plan;
  queue<int> to_visit;
  int visited[201] = { 0, };

  for(int i = 0; i < m; i++) {
    scanf(" %d", &input_tmp);
    plan.push_back(input_tmp);
  }

  if(m == 1) {
    printf("YES");
    return 0;
  }

  start = plan[0];
  
  for(int i = 1; i < m; i++) {
    next = plan[i];
    flag = false;

    if(start == next) {
      flag = true;
      continue;
    }

    // BFS로 start -> next 도달이 가능한지 확인
    to_visit.push(start - 1);
    visited[start - 1] = 1;

    while(!to_visit.empty()) {
      int front = to_visit.front();
      to_visit.pop();

      if(front == next - 1) {
        flag = true;
        break;
      }

      for(int j = 0; j < n; j++) {
        if(front == j) {
          continue;
        }
        
        if(map[front][j] == 1 && visited[j] == 0) {
          to_visit.push(j);
          visited[j] = 1;
        }
      }
    }

    if(!flag) {
      break;
    }

    to_visit = queue<int> ();
    fill(visited, visited + 201, 0);

    start = next;
  }

  if(flag) {
    printf("YES");
  } else {
    printf("NO");
  }

  return 0;
}