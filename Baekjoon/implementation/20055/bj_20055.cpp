#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {

  int n = 0;
  int k = 0;

  int input_tmp = 0;
  int zero_cnt = 0;
  int answer = 0;

  cin >> n >> k;

  deque<int> belt;
  deque<int> robot_place;

  for(int i = 0; i < (2 * n); i++) {
    cin >> input_tmp;
    belt.push_back(input_tmp);
    robot_place.push_back(0);
  }

  while(zero_cnt < k) { // 내구도가 0인 칸이 k개 이상이면 멈춤
    // 벨트가 회전
    int back = belt.back();
    belt.pop_back();
    belt.push_front(back);

    // 내리는 곳에 도달한 로봇 처리
    if(robot_place[n - 2] == 1) {
      robot_place[n - 2] = 0;
    }

    back = robot_place.back();
    robot_place.pop_back();
    robot_place.push_front(back);

    // 이동할 수 있는 경우 로봇 이동
    for(int i = (2 * n) - 1; i >= 0; i--) {
      if(robot_place[i] == 1) {
        if(i == (2 * n) - 1) {
          if(robot_place[0] == 0 && belt[0] > 0) {
            robot_place[i] = 0;
            robot_place[0] = 1;
            belt[0]--;

            if(belt[0] == 0) {
              zero_cnt++;
            }
          }
        } else {
          if(robot_place[i + 1] == 0 && belt[i + 1] > 0) {
            robot_place[i] = 0;

            if(i != n - 2) {
              robot_place[i + 1] = 1;
            }

            belt[i + 1]--;

            if(belt[i + 1] == 0) {
              zero_cnt++;
            }
          }
        }
      }
    }

    // 올리는 칸에 로봇을 올린다
    if(belt[0] > 0 && robot_place[0] == 0) {
      robot_place[0] = 1;
      belt[0]--;

      if(belt[0] == 0) {
        zero_cnt++;
      }
    }

    answer++;
  }

  cout << answer;

  return 0;
}