#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAP[101][101];

struct Shark {
  int size;
  int r;
  int c;
  int velocity;
  int dir;
};

bool compare(Shark a, Shark b) {
  return a.size > b.size;
}

int main() {

  int size_r = 0;
  int size_c = 0;

  int m = 0;

  cin >> size_r >> size_c >> m;

  vector<Shark> sharks;
  int answer = 0;

  for(int i = 0; i < m; i++) {
    Shark input;

    cin >> input.r >> input.c >> input.velocity >> input.dir >> input.size;

    MAP[input.r][input.c] = input.size;
    sharks.push_back(input);
  }

  sort(sharks.begin(), sharks.end(), compare);

  int move_r[4] = {-1, 1, 0, 0};
  int move_c[4] = {0, 0, 1, -1};

  for(int col = 1; col <= size_c; col++) {
    // 상어를 잡는다.
    for(int row = 1; row <= size_r; row++) {
      if(MAP[row][col] != 0) {
        answer += MAP[row][col];
        // 상어 제거
        for(int k = 0; k < m; k++) {
          if(MAP[row][col] == sharks[k].size) {
            sharks[k].size = 0;
            break;
          }
        }

        MAP[row][col] = 0;
        break;
      }
    }

    // 상어 이동시키기
    for(int i = 0; i < m; i++) {
      if(sharks[i].size == 0) {
        continue;
      }

      int velocity = sharks[i].velocity;
      int dir = sharks[i].dir;

      int x = sharks[i].r;
      int y = sharks[i].c;

      int move = 0;

      // 속력만큼 이동
      if(dir <= 2) {
        move = velocity % ((size_r - 1) * 2);
      } else {
        move = velocity % ((size_c - 1) * 2);
      }

      for(int k = 0; k < move; k++) {
        if(dir <= 2) {
          if(x + move_r[dir - 1] <= 0 || x + move_r[dir - 1] > size_r) {
            if(dir == 1) {
              dir = 2;
            } else {
              dir = 1;
            }
          }

          x = x + move_r[dir - 1];
        } else {
          if(y + move_c[dir - 1] <= 0 || y + move_c[dir - 1] > size_c) {
            if(dir == 3) {
              dir = 4;
            } else {
              dir = 3;
            }
          }
          
          y = y + move_c[dir - 1];
        }
      }

      // 도착
      if(MAP[sharks[i].r][sharks[i].c] == sharks[i].size) {
        MAP[sharks[i].r][sharks[i].c] = 0;
      }

      if(MAP[x][y] > sharks[i].size) { 
        // 먹힌다
        sharks[i].size = 0;
      } else {
        MAP[x][y] = sharks[i].size;
        sharks[i].r = x;
        sharks[i].c = y;
        sharks[i].dir = dir;
      }
    }
  }

  cout << answer;

  return 0;
}