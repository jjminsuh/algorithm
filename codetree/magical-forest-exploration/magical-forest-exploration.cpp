#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Gollem {
  int id;
  int col;
  int exit;
};

vector<Gollem> gollems;
vector<vector<int> > map;

bool can_go_down(int row, int col, int r, int c) {
  bool can_go = false;
  if(row + 2 >= 0 && row + 2 < r) {
      if(map[row + 2][col] == 0) {
        if(row + 1 >= 0) {
          if(map[row + 1][col - 1] == 0 && map[row + 1][col + 1] == 0) {
            can_go = true;
          }
        } else {
          can_go = true;
        }
      }
    }
  return can_go;
}

pair<pair<int, int>, bool> move_gollem(Gollem gollem, int r, int c) {
  // 골렘 움직이기
  int exit = gollem.exit;

  // 골렘 중심좌표 기준으로 움직임
  int row = -2;
  int col = gollem.col;

  while(true) {
    // 남쪽으로 갈 수 있는지 확인
    if(row + 2 >= 0 && row + 2 < r) {
      if(map[row + 2][col] == 0) {
        if(row + 1 >= 0) {
          if(map[row + 1][col - 1] == 0 && map[row + 1][col + 1] == 0) {
            row++;
            continue;
          }
        } else {
          row++;
          continue;
        }
      }
    } else if(row + 2 >= r) {
      break;
    }

    // 서쪽 방향으로 회전하면서 갈 수 있는지 확인
    bool can_move_west = true;
    if(col - 2 < 0) {
      can_move_west = false;
    } else {
      if(row >= 0 && row < r && map[row][col - 2] != 0) {
        can_move_west = false;
      } else {
        if(row - 1 >= 0 && row - 1 < r && map[row - 1][col - 1] != 0) {
          can_move_west = false;
        }

        if(row + 1 >= 0 && row + 1 < r && map[row + 1][col - 1] != 0) {
          can_move_west = false;
        }
      }
    }

    if(can_move_west) {
      can_move_west = can_go_down(row, col - 1, r, c);
    }

    if(can_move_west) { 
        row = row + 1;
        col = col - 1;
        if(exit == 0) {
          exit = 3;
        } else {
          exit--;
        }

        continue;
    }

    // 동쪽 방향으로 회전하면서 갈 수 있는지 확인
    bool can_move_east = true;
    if(col + 2 >= c) {
      can_move_east = false;
    } else {
      if(row >= 0 && row < r && map[row][col + 2] != 0) {
        can_move_east = false;
      } else {
        if(row - 1 >= 0 && row - 1 < r && map[row - 1][col + 1] != 0) {
          can_move_east = false;
        }

        if(row + 1 >= 0 && row + 1 < r && map[row + 1][col + 1] != 0) {
          can_move_east = false;
        }
      }
    }
    
    if(can_move_east) {
      can_move_east = can_go_down(row, col + 1, r, c);
    }

    if(can_move_east) {
        row = row + 1;
        col = col + 1;
        if(exit == 3) {
          exit = 0;
        } else {
          exit++;
        }

        continue;
    }

    // 더 이상 움직일 수 없음
    break;
  }


  // 골렘의 위치 채우기
  // 골렘이 존재하는 위치는 1, exit만 2로 표시
  int r_way[4] = {-1, 0, 1, 0};
  int c_way[4] = {0, 1, 0, -1};
  if(row >= 1 && row <= r - 2 && col >= 1 && col <= c - 2) {
    map[row][col] = gollem.id;

    for(int i = 0; i < 4; i++) {
      if(i == exit) {
        map[row + r_way[i]][col + c_way[i]] = gollem.id + 1000;
      } else {
        map[row + r_way[i]][col + c_way[i]] = gollem.id;
      }
    }
  } else {  // 골렘이 숲을 벗어남
    return make_pair(make_pair(row, col), false);
  }

  return make_pair(make_pair(row, col), true);
}

int move_elemental(int start_r, int start_c, int r, int c) {
  // 갈 수 있는 가장 큰 행번호 찾기
  int max = start_r;

  queue<pair<int, int> > to_visit;
  vector<vector<bool> > visited(r, vector<bool>(c, false));
  to_visit.push(make_pair(start_r, start_c));
  visited[start_r][start_c] = true;

  int r_way[4] = {-1, 0, 1, 0};
  int c_way[4] = {0, 1, 0, -1};

  while(!to_visit.empty()) {
    pair<int, int> front = to_visit.front();
    to_visit.pop();

    if(max < front.first) {
      max = front.first;
    }

    for(int i = 0; i < 4; i++) {
      if(front.first + r_way[i] >= 0 && front.first + r_way[i] < r && front.second + c_way[i] >= 0 && front.second + c_way[i] < c) {
        if(!visited[front.first + r_way[i]][front.second + c_way[i]]){
          if(map[front.first][front.second] > 1000) {
            if(map[front.first + r_way[i]][front.second + c_way[i]] != 0) {
              to_visit.push(make_pair(front.first + r_way[i], front.second + c_way[i]));
              visited[front.first + r_way[i]][front.second + c_way[i]] = true;
            }
          } else {
            if(map[front.first + r_way[i]][front.second + c_way[i]] != 0 && map[front.first + r_way[i]][front.second + c_way[i]] % 1000 == map[front.first][front.second] % 1000) {
              to_visit.push(make_pair(front.first + r_way[i], front.second + c_way[i]));
              visited[front.first + r_way[i]][front.second + c_way[i]] = true;
            }
          }
        }
      }
    }
  }

  return max + 1;
}


int main() {

  int r = 0;
  int c = 0;
  int k = 0;

  cin >> r >> c >> k;

  map.resize(r, vector<int>(c, 0));

  for(int i = 0; i < k; i++) {
    int col = 0;
    int d = 0;

    cin >> col >> d;

    Gollem new_gollem;
    new_gollem.id = i + 1;
    new_gollem.col = col - 1;
    new_gollem.exit = d;

    gollems.push_back(new_gollem);
  }

  int answer = 0;

  // 순차적으로 골렘 입장
  for(int i = 0; i < k; i++) {
    // 골렘 최대 위치까지 이동
    pair<pair<int, int>, bool> result_move_gollem = move_gollem(gollems[i], r, c);

    // 골렘이 숲에 들어온 경우
    if(result_move_gollem.second) {
      // 정령이 움직임
      answer += move_elemental(result_move_gollem.first.first, result_move_gollem.first.second, r, c);
    } else {
      // 모든 골렘들이 숲을 빠져나간다
      for(int m = 0; m < r; m++) {
        for(int n = 0; n < c; n++) {
          map[m][n] = 0;
        }
      }
    }
    
  }

  cout << answer;

  return 0;
}