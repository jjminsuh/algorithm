#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int main() {

  int n = 0;
  int m = 0;
  int map[1001][1001] = { 0, };
  int start_x = 0;
  int start_y = 0;

  queue<pair<int, int> > to_visit;
  int visited[1001][1001] = { 0, };
  memset(visited, -1, sizeof(visited));

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf(" %d", &map[i][j]);
      
      if(map[i][j] == 2) {
        start_x = i;
        start_y = j;
      }

      if(map[i][j] == 0) {
        visited[i][j] = 0;
      }
    }
  }

  to_visit.push(make_pair(start_x, start_y));
  visited[start_x][start_y] = 0;

  int check_row[4] = {0, 1, 0, -1};
  int check_col[4] = {1, 0, -1, 0};

  while(!to_visit.empty()) {
    pair<int, int> front = to_visit.front();
    int r = front.first;
    int c = front.second;
    to_visit.pop();

    for(int i = 0; i < 4; i++) {
      if(r + check_row[i] >= 0 && r + check_row[i] < n && c + check_col[i] >= 0 && c + check_col[i] < m) {
        if(visited[r + check_row[i]][c + check_col[i]] != -1) {
          continue;
        }

        to_visit.push(make_pair(r + check_row[i], c + check_col[i]));
        visited[r + check_row[i]][c + check_col[i]] = visited[r][c] + 1;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", visited[i][j]);
    }
    printf("\n");
  }

  return 0;
}