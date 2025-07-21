#include <iostream>
#include <stack>

using namespace std;

int main() {
  
  int n = 0;
  int answer = 0;

  cin >> n;

  stack<int> building_size;
  int iter = 1;

  for(int i = 0; i < n; i++) {
    int x = 0;
    int y = 0;

    cin >> x >> y;

    // 좌표 위치 맞춰주기
    while(!building_size.empty() && iter < x) {
      building_size.push(building_size.top());
      iter++;
    }

    // 새 건물의 높이가 낮은 경우 앞선 건물 개수 세주기
    while(!building_size.empty() && building_size.top() > y) {
      int height = building_size.top();

      while(!building_size.empty()) {
        if(building_size.top() != height) {
          break;
        }

        building_size.pop();
      }

      if(height != 0) {
        answer++;
      }
    }

    building_size.push(y);
    iter++;
  }

  // 스택에 남아있는 높이 값으로 추가 건물 세주기
  while(!building_size.empty()) {
      int height = building_size.top();

      while(!building_size.empty()) {
        if(building_size.top() != height) {
          break;
        }

        building_size.pop();
      }

      if(height != 0) {
        answer++;
      }
  }

  cout << answer;

  return 0;
}