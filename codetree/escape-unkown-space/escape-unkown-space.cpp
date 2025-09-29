#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct time_transform {
  int r;
  int c;
  int d;
  int v;
};

struct point {
  int map;
  int r;
  int c;
};

vector<vector<int> > init_map;
vector<vector<int> > east_map;
vector<vector<int> > west_map;
vector<vector<int> > south_map;
vector<vector<int> > north_map;
vector<vector<int> > top_map;
map<int, vector<time_transform> > times;

int wall_r = -1;
int wall_c = -1;

int r_way[4] = {0, 0, 1, -1};
int c_way[4] = {1, -1, 0, 0};

vector<int> get_dim(int t) {
  vector<int> dim;

  for(int i = 1; i <= t; i++) {
    if(t % i == 0) {
      dim.push_back(i);
    }
  }

  return dim;
}

void do_time_sim(int N, int M, int t) {
  // 해당 시간의 map 변화 기록
    vector<int> dim = get_dim(t);

    for(int i = 0; i < dim.size(); i++) {
      vector<time_transform> time_to_change = times[dim[i]];

      // 시간 변화에 대한 변화 기록
      for(int j = 0; j < time_to_change.size(); j++) {
        int next_r = time_to_change[j].r + r_way[time_to_change[j].d];
        int next_c = time_to_change[j].c + c_way[time_to_change[j].d];

        // 벽타고 확산도 가능...?
        // 확산 가능한지 확인
        if(next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {
          if(init_map[next_r][next_c] == 0) {
            // 확산
            init_map[next_r][next_c] = 1;

            times[dim[i]][j].r = next_r;
            times[dim[i]][j].c = next_c;

            continue;
          }
        }

        // 확산 불가능한 경우 -> 해당 시간 이동 현상 삭제
        times[dim[i]].erase(times[dim[i]].begin() + j);
      }
    }

    return;
}

int simualtion(int N, int M, point start) {
  int t = 0;
  queue<point> to_visit;
  queue<point> next_visit;

  vector<vector<bool> > init_visited(N, vector<bool>(N, false));
  vector<vector<bool> > east_visited(M, vector<bool>(M, false));
  vector<vector<bool> > west_visited(M, vector<bool>(M, false));
  vector<vector<bool> > south_visited(M, vector<bool>(M, false));
  vector<vector<bool> > north_visited(M, vector<bool>(M, false));
  vector<vector<bool> > top_visited(M, vector<bool>(M, false));

  // 초기 시작 지점 넣기
  next_visit.push(start);
  top_visited[start.r][start.c] = true;

  while(!next_visit.empty()) {
    // 시간 증가
    t++;
    
    while(!next_visit.empty()) {
      to_visit.push(next_visit.front());
      next_visit.pop();
    }

    // 시간 이상 현상 실행
    do_time_sim(N, M, t);

    while(!to_visit.empty()){
      // 이번 타임에 방문 가능한 위치들 bfs로 search -> 가능한 곳 next_visit에 저장
      point front = to_visit.front();
      to_visit.pop();

      if(front.map == 0) { // 내가 바닥에 있는 경우
        for(int i = 0; i < 4; i++) {
          int next_r = front.r + r_way[i];
          int next_c = front.c + c_way[i];

          // 범위 안에 들어올 때
          if(next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {
            if(init_map[next_r][next_c] == 4) { // 탈출구인 경우
              // 바로 t return 종료!
              return t + 1;
            } else if(init_map[next_r][next_c] == 0 && !init_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 0;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              init_visited[next_r][next_c] = true;
            } else if(init_map[next_r][next_c] == 3) {
              // 벽 탈 수 있는 경우
              if(i == 0) { // 동쪽 -> 서쪽 벽 확인
                next_r = M - 1;
                next_c = next_r - (wall_r - 1);

                if(west_map[next_r][next_c] == 0 && !west_visited[next_r][next_c]) {
                  // 다음 탐색 후보가 됨
                  point new_point;
                  new_point.map = 2;
                  new_point.r = next_r;
                  new_point.c = next_c;
                  next_visit.push(new_point);
                  west_visited[next_r][next_c] = true;
                }
              } else if(i == 1) { // 서쪽 -> 동쪽 벽 확인
                next_r = M - 1;
                next_c = -1 * (next_r - (wall_r - 1) - M);

                if(east_map[next_r][next_c] == 0 && !east_visited[next_r][next_c]) {
                  // 다음 탐색 후보가 됨
                  point new_point;
                  new_point.map = 1;
                  new_point.r = next_r;
                  new_point.c = next_c;
                  next_visit.push(new_point);
                  east_visited[next_r][next_c] = true;
                }
              } else if(i == 2) { // 남쪽 -> 북쪽 벽 확인
                next_r = M - 1;
                next_c = -1 * (next_c - (wall_c - 1) - M);

                if(north_map[next_r][next_c] == 0 && !north_visited[next_r][next_c]) {
                  // 다음 탐색 후보가 됨
                  point new_point;
                  new_point.map = 4;
                  new_point.r = next_r;
                  new_point.c = next_c;
                  next_visit.push(new_point);
                  north_visited[next_r][next_c] = true;
                }
              } else { // 북쪽 -> 남쪽 벽 확인
                next_r = M - 1;
                next_c = next_r - (wall_r - 1);

                if(south_map[next_r][next_c] == 0 && !south_visited[next_r][next_c]) {
                  // 다음 탐색 후보가 됨
                  point new_point;
                  new_point.map = 3;
                  new_point.r = next_r;
                  new_point.c = next_c;
                  next_visit.push(new_point);
                  south_visited[next_r][next_c] = true;
                }
              }
            }
          }
        }
      } else if(front.map == 1) { // 내가 동쪽 map에 있는 경우
        for(int i = 0; i < 4; i++) {
          int next_r = front.r + r_way[i];
          int next_c = front.c + c_way[i];

          // 범위 안에 들어올 때
          if(next_r >= 0 && next_r < M && next_c >= 0 && next_c < M) {
            if(east_map[next_r][next_c] == 0 && !east_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 1;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              east_map[next_r][next_c] = true;
            } 
          } else if(next_r == -1 && next_c >= 0 && next_c < M) { // 위쪽 벽으로 이동 가능
            next_r = M - 1 - next_c;
            next_c = M - 1;

            if(top_map[next_r][next_c] == 0 && !top_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 5;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              top_visited[next_r][next_c] = true;
            } 
          } else if(next_c == -1 && next_r >= 0 && next_c < M) { // 남쪽 벽으로 이동
            next_c = M - 1;

            if(south_map[next_r][next_c] == 0 && !south_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 3;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              south_visited[next_r][next_c] = true;
            }
          } else if(next_c == M && next_r >= 0 && next_c < M) { // 북쪽 벽으로 이동
            next_c = 0;

            if(north_map[next_r][next_c] == 0 && !north_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 4;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              north_visited[next_r][next_c] = true;
            }
          } else if(next_r == M) { // 바닥으로 이동 가능
            next_r = wall_r + (M - 1 - next_c);
            next_c = wall_c + M;

            if(init_map[next_r][next_c] == 0 && !init_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 0;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              init_visited[next_r][next_c] = true;
            }
          }
        }
      } else if(front.map == 2) { // 내가 서쪽에 있는 경우
        for(int i = 0; i < 4; i++) {
          int next_r = front.r + r_way[i];
          int next_c = front.c + c_way[i];

          // 범위 안에 들어올 때
          if(next_r >= 0 && next_r < M && next_c >= 0 && next_c < M) {
            if(west_map[next_r][next_c] == 0 && !west_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 2;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              west_visited[next_r][next_c] = true;
            } 
          } else if(next_r == -1 && next_c >= 0 && next_c < M) { // 위쪽 벽으로 이동 가능
            next_r = next_c;
            next_c = 0;

            if(top_map[next_r][next_c] == 0 && !top_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 5;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              top_visited[next_r][next_c] = true;
            } 
          } else if(next_c == -1 && next_r >= 0 && next_c < M) { // 북쪽 벽으로 이동
            next_c = M - 1;

            if(north_map[next_r][next_c] == 0 && !north_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 4;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              north_visited[next_r][next_c] = true;
            }
          } else if(next_c == M && next_r >= 0 && next_c < M) { // 남쪽 벽으로 이동
            next_c = 0;

            if(south_map[next_r][next_c] == 0 && !south_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 3;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              south_visited[next_r][next_c] = true;
            }
          } else if(next_r == M) { // 바닥으로 이동 가능
            next_r = wall_r + next_c;
            next_c = wall_c - 1;

            if(init_map[next_r][next_c] == 0 && !init_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 0;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              init_visited[next_r][next_c] = true;
            }
          }
        }
      } else if(front.map == 3) { // 내가 남쪽에 있는 경우
        for(int i = 0; i < 4; i++) {
          int next_r = front.r + r_way[i];
          int next_c = front.c + c_way[i];

          // 범위 안에 들어올 때
          if(next_r >= 0 && next_r < M && next_c >= 0 && next_c < M) {
            if(south_map[next_r][next_c] == 0 && !south_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 3;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              south_visited[next_r][next_c] = true;
            } 
          } else if(next_r == -1 && next_c >= 0 && next_c < M) { // 위쪽 벽으로 이동 가능
            next_r = M - 1;

            if(top_map[next_r][next_c] == 0 && !top_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 5;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              top_visited[next_r][next_c] = true;
            } 
          } else if(next_c == -1 && next_r >= 0 && next_c < M) { // 서쪽 벽으로 이동
            next_c = M - 1;

            if(west_map[next_r][next_c] == 0 && !west_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 2;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              west_visited[next_r][next_c] = true;
            }
          } else if(next_c == M && next_r >= 0 && next_c < M) { // 동쪽 벽으로 이동
            next_c = 0;

            if(east_map[next_r][next_c] == 0 && !east_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 1;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              east_visited[next_r][next_c] = true;
            }
          } else if(next_r == M) { // 바닥으로 이동 가능
            next_r = wall_r + M;
            next_c = wall_c + next_c;

            if(init_map[next_r][next_c] == 0 && !init_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 0;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              init_visited[next_r][next_c] = true;
            }
          }
        }
      } else if(front.map == 4) { // 내가 북쪽에 있는 경우
        for(int i = 0; i < 4; i++) {
          int next_r = front.r + r_way[i];
          int next_c = front.c + c_way[i];

          // 범위 안에 들어올 때
          if(next_r >= 0 && next_r < M && next_c >= 0 && next_c < M) {
            if(south_map[next_r][next_c] == 0 && !south_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 3;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              south_visited[next_r][next_c] = true;
            } 
          } else if(next_r == -1 && next_c >= 0 && next_c < M) { // 위쪽 벽으로 이동 가능
            next_r = 0;
            next_c = M - 1 - next_c;

            if(top_map[next_r][next_c] == 0 && !top_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 5;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              top_visited[next_r][next_c] = true;
            } 
          } else if(next_c == -1 && next_r >= 0 && next_c < M) { // 동쪽 벽으로 이동
            next_c = M - 1;

            if(east_map[next_r][next_c] == 0 && !east_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 1;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              east_visited[next_r][next_c] = true;
            }
          } else if(next_c == M && next_r >= 0 && next_c < M) { // 서쪽 벽으로 이동
            next_c = 0;

            if(west_map[next_r][next_c] == 0 && !west_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 2;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              west_visited[next_r][next_c] = true;
            }
          } else if(next_r == M) { // 바닥으로 이동 가능
            next_r = wall_r - 1;
            next_c = wall_c + M - 1 - next_c;

            if(init_map[next_r][next_c] == 0 && !init_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 0;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              init_visited[next_r][next_c] = true;
            }
          }
        }
      } else if(front.map == 5) { // 내가 위쪽에 있는 경우
        for(int i = 0; i < 4; i++) {
          int next_r = front.r + r_way[i];
          int next_c = front.c + c_way[i];

          // 범위 안에 들어올 때
          if(next_r >= 0 && next_r < M && next_c >= 0 && next_c < M) {
            if(top_map[next_r][next_c] == 0 && !top_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 5;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              top_visited[next_r][next_c] = true;
            } 
          } else if(next_r == -1 && next_c >= 0 && next_c < M) { // 북쪽 벽으로 이동 가능
            next_r = 0;
            next_c = M - 1 - next_c;

            if(north_map[next_r][next_c] == 0 && !north_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 4;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              north_visited[next_r][next_c] = true;
            } 
          } else if(next_c == -1 && next_r >= 0 && next_c < M) { // 서쪽 벽으로 이동
            next_r = 0;
            next_c = next_r;

            if(west_map[next_r][next_c] == 0 && !west_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 2;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              west_visited[next_r][next_c] = true;
            }
          } else if(next_c == M && next_r >= 0 && next_c < M) { // 동쪽 벽으로 이동
            next_r = 0;
            next_c = M - 1 - next_c;

            if(east_map[next_r][next_c] == 0 && !east_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 1;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              east_visited[next_c][next_r] = true;
            }
          } else if(next_r == M && next_c <= 0 && next_c < M) { // 남쪽으로 이동 가능
            next_r = 0;

            if(south_map[next_r][next_c] == 0 && !south_visited[next_r][next_c]) { // 빈 공간인 경우
              // 다음 탐색 후보가 됨
              point new_point;
              new_point.map = 3;
              new_point.r = next_r;
              new_point.c = next_c;
              next_visit.push(new_point);
              south_visited[next_r][next_c] = true;
            }
          }
        }
      }
    }

    cout << t << "\n";

    for(int i = 0; i < M; i++) {
      for(int j = 0; j < M; j++) {
        cout << south_visited[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }

  // 여기에 도달하면 탈출구 접근 불가능
  return -1;
}

int main() {
  // 입력 받기
  int N = 0;
  int M = 0; 
  int F = 0;
  point start;

  cin >> N >> M >> F;

  // map 번호 순서대로 0, 1, 2, 3, 4, 5
  init_map.resize(N, vector<int>(N, 0));
  east_map.resize(M, vector<int>(M, 0));
  west_map.resize(M, vector<int>(M, 0));
  south_map.resize(M, vector<int>(M, 0));
  north_map.resize(M, vector<int>(M, 0));
  top_map.resize(M, vector<int>(M, 0));

  // 밑면 단면도
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> init_map[i][j];

      if(init_map[i][j] == 3 && wall_r == -1 && wall_c == -1) {
        wall_r = i;
        wall_c = j;
      }
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      cin >> east_map[i][j];
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      cin >> west_map[i][j];
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      cin >> south_map[i][j];
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      cin >> north_map[i][j];
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      cin >> top_map[i][j];
      if(top_map[i][j] == 2) {
        start.map = 5;
        start.r = i;
        start.c = j;
      }
    }
  }

  // 시간 이상 현상 저장
  for(int i = 0; i < F; i++) {
    int r = 0;
    int c = 0;
    int d = 0;
    int v = 0;

    cin >> r >> c >> d >> v;

    init_map[r][c] = 1;

    time_transform new_time;
    new_time.r = r;
    new_time.c = c;
    new_time.d = d;
    new_time.v = v;

    times[v].push_back(new_time);
  }

  int answer = 0;

  answer = simualtion(N, M, start);

  cout << answer;

  return 0;
}