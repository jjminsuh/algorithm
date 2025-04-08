#include <iostream>
#include <vector>

using namespace std;

int total = 0;
int percent[9] = {1, 1, 2, 2, 5, 7, 7, 10, 10};
int map[500][500];

void after_storm(pair<int, int> y, int dir, int n, vector<vector<int> > move_r, vector<vector<int> > move_c) {
  int r = y.first;
  int c = y.second;
  int sand = map[r][c];
  int sand_move = 0;

  // 각 칸에 남는 모래 계산
  for(int i = 0; i < 9; i++) {
    if(r + move_r[dir - 1][i] >= 0 && r + move_r[dir - 1][i] < n && c + move_c[dir - 1][i] >= 0 && c + move_c[dir - 1][i] < n) {
      map[r + move_r[dir - 1][i]][c + move_c[dir - 1][i]] += sand * percent[i] / 100;
      sand_move += sand * percent[i] / 100;
    } else {
      total += sand * percent[i] / 100;
      sand_move += sand * percent[i] / 100;
    }
  }

  // 알파 칸에 들어가는 모래 계산
  if(r + move_r[dir - 1][9] >= 0 && r + move_r[dir - 1][9] < n && c + move_c[dir - 1][9] >= 0 && c + move_c[dir - 1][9] < n) {
    map[r + move_r[dir - 1][9]][c + move_c[dir - 1][9]] += sand - sand_move;
  } else {
    total += sand - sand_move;
  }

  map[r][c] = 0;
}


int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n = 0;

  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  // 모래 이동 방향 저장
  vector<vector<int> > move_r;
  vector<vector<int> > move_c;
  // 왼
  move_r.push_back({-1, 1, -2, 2, 0, -1, 1, -1, 1, 0});
  move_c.push_back({1, 1, 0, 0, -2, 0, 0, -1, -1, -1});
  
  // 아래
  move_r.push_back({-1, -1, 0, 0, 2, 0, 0, 1, 1, 1});
  move_c.push_back({-1, 1, -2, 2, 0, -1, 1, -1, 1, 0});

  // 오른
  move_r.push_back({1, -1, -2, 2, 0, -1, 1, -1, 1, 0});
  move_c.push_back({-1, -1, 0, 0, 2, 0, 0, 1, 1, 1});
  
  // 위
  move_r.push_back({1, 1, 0, 0, -2, 0, 0, -1, -1, -1});
  move_c.push_back({1, -1, 2, -2, 0, 1, -1, 1, -1, 0});

  int next_r[4] = {0, 1, 0, -1};
  int next_c[4] = {-1, 0, 1, 0};

  int r = n / 2;
  int c = n / 2;

  int row_cnt = 1;
  int col_cnt = 1;
  int dir = 1; // 1: 왼, 2: 아래, 3: 오른, 4: 위

  while(r >= 0 && c >= 0 && r < n && c < n) {
    if(dir % 2 != 0) {
      for(int i = 0; i < col_cnt; i++) {
        r = r + next_r[dir - 1];
        c = c + next_c[dir - 1];
        if(r >= 0 && r < n && c >= 0 && c < n) {
          after_storm(make_pair(r, c), dir, n, move_r, move_c);
        }
      }

      col_cnt++;
    } else {
      for(int i = 0; i < row_cnt; i++) {
        r = r + next_r[dir - 1];
        c = c + next_c[dir - 1];
        if(r >= 0 && r < n && c >= 0 && c < n) {
          after_storm(make_pair(r, c), dir, n, move_r, move_c);
        }
      }

      row_cnt++;
    }

    if(dir == 4) {
      dir = 1;
    } else {
      dir++;
    }
  }

  cout << total;

  return 0;
}