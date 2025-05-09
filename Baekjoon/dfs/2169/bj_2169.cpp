#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  int m = 0;

  cin >> n >> m;

  vector<vector<int> > map(n, vector<int>(m, 0));
  vector<vector<int> > value(n, vector<int>(m, 0));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  // 가장 첫줄 max value는 왼쪽에서 오는 방법 밖에 없으므로 미리 채워주기
  value[0][0] = map[0][0];

  for(int i = 1; i < m; i++) {
    value[0][i] = value[0][i - 1] + map[0][i];
  }

  vector<vector<int> > find_max(2, vector<int>(m, 0));

  for(int i = 1; i < n; i++) {
    // 왼쪽에서 오는 경우 max 찾기
    for(int j = 0; j < m; j++) {
      if(j - 1 < 0) {
        find_max[0][j] = value[i - 1][j] + map[i][j];
        continue;
      }

      find_max[0][j] = max(find_max[0][j - 1] + map[i][j], value[i - 1][j] + map[i][j]);
    }

    // 오른쪽에서 오는 경우 max 찾기
    for(int j = m - 1; j >= 0; j--) {
      if(j + 1 >= m) {
        find_max[1][j] = value[i - 1][j] + map[i][j];
        continue;
      }

      find_max[1][j] = max(find_max[1][j + 1] + map[i][j], value[i - 1][j] + map[i][j]);
    }

    // 해당 row의 max value 채우기
    for(int j = 0; j < m; j++) {
      value[i][j] = max(find_max[0][j], find_max[1][j]);
    }
  }

  cout << value[n - 1][m - 1];

  return 0;
}