#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct FireBall {
  int r;
  int c;
  int mass;
  int dir;
  int speed;
};

vector<FireBall> MAP[51][51];

int main() {

  int answer = 0;

  int n = 0;
  int m = 0;
  int k = 0;

  cin >> n >> m >> k;

  queue<FireBall> balls;

  for(int i = 0; i < m; i++) {
    FireBall input;

    cin >> input.r >> input.c >> input.mass >> input.speed >> input.dir;
    
    balls.push(input);
  }

  // 이동 방향 정의
  int move_r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int move_c[8] = {0, 1, 1, 1, 0, -1, -1, -1};

  for(int i = 0; i < k; i++) {
    // 파이어볼 이동
    while(!balls.empty()) {
      FireBall front = balls.front();
      balls.pop();

      // 이동 해야하는 칸 계산
      int move = front.speed % n; // 제자리로 돌아오는 이동을 무시하기 위해 mod 계산

      // 남은 move만큼은 한 칸씩 이동
      int r_new = front.r;
      int c_new = front.c;
      int dir = front.dir;

      for(int t = 0; t < move; t++) {
        if(r_new + move_r[dir] <= 0) {
          r_new = n;
        } else if(r_new + move_r[dir] > n) {
          r_new = 1;
        } else {
          r_new += move_r[dir];
        }
        
        if(c_new + move_c[dir] <= 0) {
          c_new = n;
        } else if(c_new + move_c[dir] > n) {
          c_new = 1;
        } else {
          c_new += move_c[dir];
        }
      }

      front.r = r_new;
      front.c = c_new;

      MAP[r_new][c_new].push_back(front);
    }

    // 파이어볼 합치기
    for(int row = 1; row <= n; row++) {
      for(int col = 1; col <= n; col++) {
        if(MAP[row][col].size() == 1) {
          balls.push(MAP[row][col][0]);
          MAP[row][col].clear();
          continue;
        }

        if(MAP[row][col].size() > 1) {  // 파이어 볼이 2개 이상 존재하는 경우
          int mass_total = 0;
          int speed_total = 0;
          int cnt = MAP[row][col].size();
          bool dir_same = true;
          bool base_dir = true;

          for(int j = 0; j < MAP[row][col].size(); j++) {
            mass_total += MAP[row][col][j].mass;
            speed_total += MAP[row][col][j].speed;

            if(j == 0) {
              base_dir = (MAP[row][col][j].dir % 2 == 0);
            } else {
              if(base_dir != (MAP[row][col][j].dir % 2 == 0)) {
                dir_same = false;
              }
            }
          }

          MAP[row][col].clear();

          for(int j = 0; j < 4; j++) {
            FireBall new_ball;

            new_ball.mass = mass_total / 5;
            
            if(new_ball.mass == 0) {
              continue;
            }
            
            new_ball.r = row;
            new_ball.c = col;
            
            new_ball.speed = speed_total / cnt;
            if(dir_same) {
              new_ball.dir = j * 2;
            } else {
              new_ball.dir = (j * 2) + 1;
            }

            balls.push(new_ball);
          }
        }
      }
    }
  }

  while(!balls.empty()) {
    answer += balls.front().mass;
    balls.pop();
  }

  cout << answer;

  return 0;
}