#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <stack>

using namespace std;

int main() {

  int n = 0;
  int l = 0;
  int r = 0;
  int tmp_num = 0;
  vector<int> tmp_row;
  vector<vector<int> > map;
  int visited[50][50] = {0, };
  queue<pair<int, int> > to_visit;

  scanf("%d %d %d", &n, &l, &r);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf(" %d", &tmp_num);
      tmp_row.push_back(tmp_num);
      // to_visit.push(make_pair(i, j));
    }

    map.push_back(tmp_row);
    tmp_row.clear();
  }

  int answer = 0;
  int sum = 0;
  int cnt = 0;
  int check_r[4] = {-1, 0, 1, 0};
  int check_c[4] = {0, -1, 0, 1};
  bool flag = true;

  while(flag) {
    flag = false;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        stack<pair<int, int> > idx;

        if(visited[i][j] != 0) {
          continue;
        }

        to_visit.push(make_pair(i, j));
        idx.push(make_pair(i, j));
        visited[i][j] = 1;
        sum = map[i][j];
        cnt = 1;
        
        while(!to_visit.empty()) {
          pair<int, int> front = to_visit.front();
          int row = front.first;
          int col = front.second;
          to_visit.pop();

          for(int k = 0; k < 4; k++) {
            if(row + check_r[k] >= 0 && row + check_r[k] < n && col + check_c[k] >= 0 && col + check_c[k] < n) {
              if(visited[row +  check_r[k]][col + check_c[k]] == 0) {
                if(abs(map[row][col] - map[row + check_r[k]][col + check_c[k]]) >= l && abs(map[row][col] - map[row + check_r[k]][col + check_c[k]]) <= r) {
                  visited[row + check_r[k]][col + check_c[k]] = 1;
                  sum += map[row + check_r[k]][col + check_c[k]];
                  cnt++;
                  to_visit.push(make_pair(row + check_r[k], col + check_c[k]));
                  idx.push(make_pair(row + check_r[k], col + check_c[k]));
                }
              }
            }
          }
        }

        if(cnt > 1) {
          flag = true;

          int new_num = sum / cnt;

          while(!idx.empty()) {
            pair<int, int> top = idx.top();
            idx.pop();
            map[top.first][top.second] = new_num;
          }
        }

        sum = 0;
        cnt = 0;
      }
    }

    if(!flag) {
      break;
    }
    
    answer += 1;

    fill(&visited[0][0], &visited[n - 1][n], 0);
  }

  printf("%d", answer);
  
  return 0;
}