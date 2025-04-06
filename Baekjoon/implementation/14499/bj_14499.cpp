#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  int m = 0;

  int x = 0;
  int y = 0;

  int k = 0;

  cin >> n >> m >> x >> y >> k;

  vector<vector<int> > map(n, vector<int>(m, 0));
  vector<int> dice(7, 0);
  int dice_top = 1;
  int dice_right = 4;
  int dice_up = 5;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  for(int i = 0; i < k; i++) {
    int dir = 0;
    cin >> dir;

    int move_r[4] = {0, 0, -1, 1};
    int move_c[4] = {1, -1, 0, 0};

    if(x + move_r[dir - 1] >= 0 && x + move_r[dir - 1] < n && y + move_c[dir - 1] >= 0 && y + move_c[dir - 1] < m) {
      x = x + move_r[dir - 1];
      y = y + move_c[dir - 1];

      int dice_tmp = dice_top;

      // 주사위 굴리기
      if(dir == 1) {
        dice_top = 7 - dice_right;
        dice_right = dice_tmp;
      } else if(dir == 2) {
        dice_top = dice_right;
        dice_right = 7 - dice_tmp;
      } else if(dir == 3) {
        dice_top = 7 - dice_up;
        dice_up = dice_tmp;
      } else {
        dice_top = dice_up;
        dice_up = 7 - dice_tmp;
      }

      // 지도가 0이면 주사위 바닥면을 복사
      if(map[x][y] == 0) {
        map[x][y] = dice[7 - dice_top];
      } else {  // 아닌 경우 주사위에 복사
        dice[7 - dice_top] = map[x][y];
        map[x][y] = 0;
      }

      cout << dice[dice_top] << "\n";
    }
  }

  return 0;
}