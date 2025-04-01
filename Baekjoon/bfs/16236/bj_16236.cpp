#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, pair<int, int> > find_to_eat(pair<int, int> now,
                                        vector<vector<int> > map,
                                        int n,
                                        int baby_shark) {
  queue<pair<int, int> > to_visit;
  vector<vector<int> > visited(n, vector<int>(n, -1));

  to_visit.push(now);
  visited[now.first][now.second] = 0;

  int r[4] = {-1, 0, 0, 1};
  int c[4] = {0, -1, 1, 0};

  // 도달할 수 있는 곳의 거리 구하기 (아기상어 크기 이하인 곳을 모두 지나갈 수 있음)
  while(!to_visit.empty()) {
    pair<int, int> front = to_visit.front();
    to_visit.pop();

    for(int i = 0; i < 4; i++) {
      if(front.first + r[i] >= 0 && front.first + r[i] < n && front.second + c[i] >= 0 && front.second + c[i] < n) {
        if(visited[front.first + r[i]][front.second + c[i]] == -1) {
          if(map[front.first + r[i]][front.second + c[i]] <= baby_shark) {
            to_visit.push(make_pair(front.first + r[i], front.second + c[i]));
            visited[front.first + r[i]][front.second + c[i]] = visited[front.first][front.second] + 1;
          }
        }
      }
    }
  }

  pair<int, pair<int, int> > result = make_pair(-1, make_pair(n + 1, n + 1));

  // 앞에서부터 순차적으로 탐색하며
  // 상어가 먹을 수 있는 물고기 중
  // 거리가 가장 짧고
  // 위에 있는 -> 왼쪽에 있는 물고기 찾기
  // bfs만 돌리면 조건에 맞는 물고기를 먹지 못한다!!
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(map[i][j] != 0 && map[i][j] < baby_shark) {
        if(visited[i][j] != -1) {
          if(result.first == -1) {
            result = make_pair(visited[i][j], make_pair(i, j));
            continue;
          }

          if(visited[i][j] == result.first) {
            if(i == result.second.first) {
              if(j < result.second.second) {
                result = make_pair(visited[i][j], make_pair(i, j));
              }
            } else {
              if(i < result.second.first) {
                result = make_pair(visited[i][j], make_pair(i, j));
              } 
            }
          } else {
            if(visited[i][j] < result.first) {
              result = make_pair(visited[i][j], make_pair(i, j));
            }
          }
        }
      }
    }
  }

  if(result.first == -1) {
    return make_pair(-1, make_pair(-1, -1));
  }

  return result;
}

int main() {

  int n = 0;

  cin >> n;

  vector<vector<int> > map(n, vector<int> (n, 0));

  pair<int, int> to_visit;

  int time = 0;

  int baby_shark = 2;
  int count = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];

      if(map[i][j] == 9) {
        to_visit = make_pair(i, j);
        map[i][j] = 0;
      }
    }
  }

  while(to_visit.first != -1) {
    pair<int, pair<int, int> > result = find_to_eat(to_visit, map, n, baby_shark);

    // 먹을 수 있는 물고기 없다면 멈춤
    if(result.first == -1) {
      break;
    }
    
    // 먹는데 걸린시간
    time += result.first;
    // 먹고 난 곳은 0이 된다
    map[result.second.first][result.second.second] = 0;
    // 먹은 물고기 개수 저장
    count++;

    // 먹은 물고기 개수가 아기 상어 크기와 같아지는 경우 상어 크기가 커진다.
    if(count == baby_shark) {
      baby_shark++;
      count = 0;
    }

    // 다음 상어출발 지점 설정
    to_visit = result.second;
  }

  cout << time;

  return 0;
}