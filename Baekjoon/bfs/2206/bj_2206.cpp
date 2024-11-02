#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {

  int answer = -1;

  int n = 0;
  int m = 0;

  vector<vector<int> > map;
  string inputTmp = "";

  scanf("%d %d\n", &n, &m);

  for(int i = 0; i < n; i++) {
    vector<int> row;

    getline(cin, inputTmp);
    
    for(int j = 0; j < m; j++) {
      row.push_back(inputTmp[j] - '0');
    }

    map.push_back(row);
    inputTmp = "";
  }

  int visited[1001][1001] = {0, };
  int visited_breaking[1001][1001] = {0, };

  // <<row, column>, hasDestoryWall>
  queue<tuple<pair<int, int>, int, int> > toVisit;

  toVisit.push(make_tuple(make_pair(0, 0), 0, 1));
  visited[0][0] = 1;

  tuple<pair<int, int>, int, int> front;
  int row = 0;
  int col = 0;
  int wall = 0;
  int depth = 0;

  int checkRow[4] = {1, 0, -1, 0};
  int checkCol[4] = {0, 1, 0, -1};

  while(!toVisit.empty()) {
    front = toVisit.front();
    row = get<0>(front).first;
    col = get<0>(front).second;
    wall = get<1>(front);
    depth = get<2>(front);

    toVisit.pop();

    if(row == n - 1 && col == m - 1) {
      answer = depth;
      break;
    }

    for(int i = 0; i < 4; i++) {
      // 탐색할 칸이 범위 안인지 판단
      if(row + checkRow[i] >= 0 && row + checkRow[i] < n && col + checkCol[i] >= 0 && col + checkCol[i] < m){

        // 이미 방문한 칸인지 확인
        if(visited[row + checkRow[i]][col + checkCol[i]] == 0) {
          // 벽을 이전에 부쉈는지 확인
          if(wall == 0) { // 벽을 부순 적이 없는 경우
            if(map[row + checkRow[i]][col + checkCol[i]] == 0) { // 벽이 아닌 경우
              toVisit.push(make_tuple(make_pair(row + checkRow[i], col + checkCol[i]), wall, depth + 1));
              visited[row + checkRow[i]][col + checkCol[i]] = 1;
            } else {
              toVisit.push(make_tuple(make_pair(row + checkRow[i], col + checkCol[i]), 1, depth + 1));
              visited_breaking[row + checkRow[i]][col + checkCol[i]] = 1;
            }
          } else { // 벽을 부순 적이 있는 경우
            if(visited_breaking[row + checkRow[i]][col + checkCol[i]] == 0) { // 벽을 부수고 도달한 적이 없는 경우
              if(map[row + checkRow[i]][col + checkCol[i]] == 0) { // 벽이 아닌 경우
                toVisit.push(make_tuple(make_pair(row + checkRow[i], col + checkCol[i]), wall, depth + 1));
                visited_breaking[row + checkRow[i]][col + checkCol[i]] = 1;
              }
            }
          }
        }
      }
    }
  }

  printf("%d", answer);

  return 0;
}