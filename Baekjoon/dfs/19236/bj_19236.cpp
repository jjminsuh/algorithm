#include <iostream>
#include <queue>

using namespace std;

int max_val = 0;

vector<vector<pair<int, int> > > move_fish(vector<vector<pair<int, int> > > map) {
  int fish_num = 1; // 현재 움직일 물고기

  // 1 ~ 16 물고기 차례로 움직이기
  while(fish_num <= 16) {
    int idx_r = 0;
    int idx_c = 0;
    bool is_found = false;

    // 물고기 위치 찾기
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        if(map[i][j].first == fish_num) {
          idx_r = i;
          idx_c = j;

          is_found = true;
          break;
        }
      }

      if(is_found) {
        break;
      }
    }

    if(!is_found) {
      fish_num++;
      continue;
    }

    // 물고기 이동하기
    int now_direction = map[idx_r][idx_c].second;

    int move_r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int move_c[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    
    for(int i = 0; i < 8; i++) {  // 자리 없으면 방향 이동해야 함
      // 현재 방향으로 이동할 수 있는지 확인
      if(idx_r + move_r[now_direction - 1] >= 0 && idx_r + move_r[now_direction - 1] < 4 && idx_c + move_c[now_direction - 1] >= 0 && idx_c + move_c[now_direction - 1] < 4) {
        if(map[idx_r + move_r[now_direction - 1]][idx_c + move_c[now_direction - 1]].first != -1) {
          // 이동하기
          pair<int, int> tmp;
          tmp = map[idx_r + move_r[now_direction - 1]][idx_c + move_c[now_direction - 1]];
          map[idx_r + move_r[now_direction - 1]][idx_c + move_c[now_direction - 1]] = make_pair(fish_num, now_direction);
          map[idx_r][idx_c] = tmp;

          break;
        }
      }

      if(now_direction == 8) {
        now_direction = 1;
      } else {
        now_direction++;
      }
    }

    // 다음 물고기 이동
    fish_num++;
  }

  return map;
}

vector<pair<int, int> > shark_next_move(vector<vector<pair<int, int> > > map, int shark_r, int shark_c, int shark_dir) {
  vector<pair<int, int> > next_move;

  int move_r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int move_c[8] = {0, -1, -1, -1, 0, 1, 1, 1};

  while(shark_r + move_r[shark_dir - 1] >= 0 && shark_r + move_r[shark_dir - 1] < 4 && shark_c + move_c[shark_dir - 1] >= 0 && shark_c + move_c[shark_dir - 1] < 4) {
    if(map[shark_r + move_r[shark_dir - 1]][shark_c + move_c[shark_dir - 1]].first != 0) {
      next_move.push_back(make_pair(shark_r + move_r[shark_dir - 1], shark_c + move_c[shark_dir - 1]));
    }

    shark_r = shark_r + move_r[shark_dir - 1];
    shark_c = shark_c + move_c[shark_dir - 1];
  }

  return next_move;
}

void move_shark(vector<vector<pair<int, int> > > map, int shark_r, int shark_c, int shark_dir, int ans) {
  vector<vector<pair<int, int> > > new_map = move_fish(map);
  vector<pair<int, int> > next_move = shark_next_move(new_map, shark_r, shark_c, shark_dir);
  
  // 상어가 더 이상 갈 곳이 없음
  if(next_move.size() == 0) {
    if(ans > max_val) {
      max_val = ans;
    }

    return;
  }

  for(int i = 0; i < next_move.size(); i++) {
    pair<int, int> to_eat = next_move[i];
    pair<int, int> fish = new_map[to_eat.first][to_eat.second];

    new_map[to_eat.first][to_eat.second] = make_pair(-1, fish.second);
    new_map[shark_r][shark_c] = make_pair(0, new_map[shark_r][shark_c].second);

    move_shark(new_map, to_eat.first, to_eat.second, fish.second, ans + fish.first);

    new_map[to_eat.first][to_eat.second] = fish;
  }

}

int main() {

  vector<vector<pair<int, int> > > map(4, vector<pair<int, int> >(4));

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      int size_input = 0;
      int direction_input = 0;

      cin >> size_input >> direction_input;

      map[i][j] = make_pair(size_input, direction_input);
    }
  }

  // 처음에 0,0에서 시작
  int answer = map[0][0].first;
  map[0][0] = make_pair(-1, map[0][0].second);

  move_shark(map, 0, 0, map[0][0].second, answer);

  cout << max_val;

  return 0;
}