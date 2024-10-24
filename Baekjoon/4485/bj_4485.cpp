#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  
  int n = 0;
  int input_tmp = 0;
  int prob_num = 1;

  int row_c[4] = {-1, 0, 1, 0};
  int col_c[4] = {0, -1, 0, 1};

  while(1) {
    scanf("%d", &n);

    if(n == 0) {
      break;
    }

    vector<vector<int> > map;
    vector<int> tmp;
  

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        scanf(" %d", &input_tmp);

        tmp.push_back(input_tmp);
      }

      map.push_back(tmp);
      tmp.clear();
    }

    queue<pair<int, int> > to_visit;
    int visited[126][126] = { 0, };
    fill(&visited[0][0], &visited[125][126], -1);

    to_visit.push(make_pair(0, 0));
    visited[0][0] = map[0][0];

    while(!to_visit.empty()) {
      pair<int, int> front = to_visit.front();
      int r = front.first;
      int c = front.second;
      to_visit.pop();

      for(int i = 0 ; i < 4; i++) {
        if(r + row_c[i] >= 0 && r + row_c[i] < n && c + col_c[i] >= 0 && c + col_c[i] < n) {
          if(visited[r + row_c[i]][c + col_c[i]] == -1) {
            visited[r + row_c[i]][c + col_c[i]] = visited[r][c] + map[r + row_c[i]][c + col_c[i]];
            to_visit.push(make_pair(r + row_c[i], c + col_c[i]));
          } else {
            if(visited[r + row_c[i]][c + col_c[i]] > visited[r][c] + map[r + row_c[i]][c + col_c[i]]) {
              visited[r + row_c[i]][c + col_c[i]] = visited[r][c] + map[r + row_c[i]][c + col_c[i]];
              to_visit.push(make_pair(r + row_c[i], c + col_c[i]));
            }
          }
        }
      }
    }

    printf("Problem %d: %d\n", prob_num, visited[n - 1][n - 1]);

    prob_num++;
  }

  return 0;
}