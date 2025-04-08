#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int n = 0;
  int m = 0;
  int k = 0;

  cin >> n >> m >> k;

  vector<vector<pair<int, pair<int, int> > > > map(n, vector<pair<int, pair<int, int>> >(n, make_pair(0, make_pair(0, 0))));
  vector<int> shark_dir(m, 0);
  vector<pair<int, int> > shark_place(m, make_pair(0, 0));
  vector<vector<vector<int> > > shark_priority(m, vector<vector<int> >(4, vector<int>(4, 0)));

  int input = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> input;
      if(input == 0) {
        map[i][j] = make_pair(input, make_pair(0, 0));
      } else {
        map[i][j] = make_pair(input, make_pair(input, k));
        shark_place[input - 1] = make_pair(i, j);
      }
    }
  }

  for(int i = 0; i < m; i++) {
    cin >> shark_dir[i];
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        cin >> shark_priority[i][j][k];
      }
    }
  }


  int time = 0;
  int shark_cnt = m;

  int dir_r[4] = {-1, 1, 0, 0};
  int dir_c[4] = {0, 0, -1, 1};

  while(time <= 1000) {
    // 1번 상어만 남는 경우 멈춤
    if(shark_cnt == 1) {
      break;
    }

    vector<int> next_move(m, -1);

    // 1번 상어 부터 상어 이동
    for(int i = 0; i < m; i++) {
      int x = shark_place[i].first;
      int y = shark_place[i].second;

      if(x == -1 && y == -1) {
        continue;
      }

      // 냄새가 없는 칸중에 갈 수 있는 칸이 있는지 확인
      for(int j = 0; j < 4; j++) {
        int check_dir = shark_priority[i][shark_dir[i] - 1][j];
        if(x + dir_r[check_dir - 1] >= 0 && x + dir_r[check_dir - 1] < n && y + dir_c[check_dir - 1] >= 0 && y + dir_c[check_dir - 1] < n) {
          if(map[x + dir_r[check_dir - 1]][y + dir_c[check_dir - 1]].second.second == 0) { 
            if(next_move[i] == -1) {
              next_move[i] = check_dir;
              break;
            }
          }
        }
      }

      // 냄새 없는 칸이 없는 경우 자기 냄새가 있는 칸으로 이동
      if(next_move[i] == -1) {
        for(int j = 0; j < 4; j++) {
          int check_dir = shark_priority[i][shark_dir[i] - 1][j];
          if(x + dir_r[check_dir - 1] >= 0 && x + dir_r[check_dir - 1] < n && y + dir_c[check_dir - 1] >= 0 && y + dir_c[check_dir - 1] < n) {
            if(map[x + dir_r[check_dir - 1]][y + dir_c[check_dir - 1]].second.first == i + 1) { // 자기 냄새가 있는 칸
              if(next_move[i] == -1) {
                next_move[i] = check_dir;
                break;
              }
            }
          }
        }
      }
    }

    // 1번 상어부터 움직이기 (모든 상어가 갈 방향이 정해진 후)
    for(int i = 0; i < m; i++) {
      int x = shark_place[i].first;
      int y = shark_place[i].second;

      if(x == -1 && y == -1) {
        continue;
      }

      // 상어 움직이기
      if(map[x + dir_r[next_move[i] - 1]][y + dir_c[next_move[i] - 1]].first < i + 1 && map[x + dir_r[next_move[i] - 1]][y + dir_c[next_move[i] - 1]].first != 0) { // 나보다 번호 낮은 상어 존재
        // 상어 쫓아내기
        map[x][y] = make_pair(0, map[x][y].second);
        shark_place[i] = make_pair(-1, -1);
        shark_cnt--;
      } else {
        map[x][y] = make_pair(0, map[x][y].second);
        map[x + dir_r[next_move[i] - 1]][y + dir_c[next_move[i] - 1]] = make_pair(i + 1, make_pair(i + 1, k + 1));
        shark_dir[i] = next_move[i];
        shark_place[i] = make_pair(x + dir_r[next_move[i] - 1], y + dir_c[next_move[i] - 1]);
      }
    }

    // 냄새 count 갱신
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(map[i][j].second.second > 1) {
          map[i][j] = make_pair(map[i][j].first, make_pair(map[i][j].second.first, map[i][j].second.second - 1));
        } else if(map[i][j].second.second == 1) {
          map[i][j] = make_pair(map[i][j].first, make_pair(0, 0));
        }
      }
    }

    time++;
  }

  if(time > 1000) {
    cout << -1;
  } else {
    cout << time;
  }

  return 0;
}