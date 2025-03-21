#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int max_size = 0;

void bfs(vector<vector<int> > map, queue<pair<int, int> > virus, int n, int m) {
  vector<vector<int> > visited(n, vector<int> (m, 0));

  int cnt = 0;

  int r[4] = {1, 0, -1, 0};
  int c[4] = {0, 1, 0, -1};

  // bfs 돌면서 바이러스 퍼지는 결과 확인
  while(!virus.empty()) {
    pair<int, int> now_visit = virus.front();
    virus.pop();

    for(int i = 0; i < 4; i++) {
      if(now_visit.first + r[i] >= 0 && now_visit.first + r[i] < n && now_visit.second + c[i] >= 0 && now_visit.second + c[i] < m ) {
        if(map[now_visit.first + r[i]][now_visit.second + c[i]] == 0) {
          if(visited[now_visit.first + r[i]][now_visit.second + c[i]] == 0) {
            map[now_visit.first + r[i]][now_visit.second + c[i]] = 2;
            virus.push(make_pair(now_visit.first + r[i], now_visit.second + c[i]));
            visited[now_visit.first + r[i]][now_visit.second + c[i]] = 1;
          }
        }
      }
    }
  }

  // 안전지대 count
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(map[i][j] == 0) {
        cnt++;
      }
    }
  }

  if(max_size < cnt) {
    max_size = cnt;
  }

  return;
}

// 벽을 세울 수 있는 모든 경우 탐색
void make_wall(vector<vector<int> > map, int depth, int n, int m, queue<pair<int, int> > virus) {
  if(depth == 3) {
    // 벽이 3개 세워지면 탐색 진행
    bfs(map, virus, n, m);
    return;
  }

  // 벽 세우기 진행
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(map[i][j] == 0) {
        map[i][j] = 1;
        make_wall(map, depth + 1, n, m, virus);
        map[i][j] = 0;
      }
    }
  }
}

int main() {

  int n = 0;
  int m = 0;
  vector<vector<int> > map;

  queue<pair<int, int> > virus;

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    vector<int> row(m);
    for(int j = 0; j < m; j++) {
      cin >> row[j];

      if(row[j] == 2) {
        virus.push(make_pair(i, j));
      }
    }

    map.push_back(row);
  }

  make_wall(map, 0, n, m, virus);

  cout << max_size;

  return 0;
}