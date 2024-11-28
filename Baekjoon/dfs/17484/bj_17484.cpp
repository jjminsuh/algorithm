#include <iostream>
#include <vector>

using namespace std;

int min_cost = 3600;

void dfs(int depth, int n, int m, vector< vector<int> > map, int cost, int r, int c, int before) {
  if(depth == n) {
    if(min_cost > cost) {
      min_cost = cost;
    }

    return;
  }

  if(before != -1 && c - 1 >= 0) {
    dfs(depth + 1, n, m, map, cost + map[r + 1][c - 1], r + 1, c - 1, -1);
  }

  if(before != 1 && c + 1 < m) {
    dfs(depth + 1, n, m, map, cost + map[r + 1][c + 1], r + 1, c + 1, 1);
  }

  if(before != 0) {
    dfs(depth + 1, n, m, map, cost + map[r + 1][c], r + 1, c, 0);
  }
}

int main() {

  int n = 0;
  int m = 0;

  scanf("%d %d", &n, &m);

  vector< vector<int> > map;
  int input_tmp = 0;

  for(int i = 0; i < n; i++) {
    vector<int> vector_tmp;

    for(int j = 0; j < m; j++) {
      scanf(" %d", &input_tmp);
      vector_tmp.push_back(input_tmp);
    }

    map.push_back(vector_tmp);
    vector_tmp.clear();
  }

  for(int i = 0; i < m; i++) {
    dfs(1, n, m, map, map[0][i], 0, i, 2);
  }

  printf("%d", min_cost);

  return 0;
}