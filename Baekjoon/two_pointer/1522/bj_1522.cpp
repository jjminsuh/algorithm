#include <iostream>
#include <string>

using namespace std;

int main() {

  string input = "";

  cin >> input;

  int a_total_cnt = 0;
  int b_total_cnt = 0;

  for(int i = 0; i < input.length(); i++){
    if(input[i] == 'a') {
      a_total_cnt++;
    } else {
      b_total_cnt++;
    }
  }

  // 전체 a의 개수만큼 슬라이딩 윈도우의 넓이를 정해서 옮겨가면서 모든 경우 획인
  int start_idx = 0;
  int last_idx = start_idx + a_total_cnt;
  int answer = b_total_cnt;

  // 원형이라 생각하므로 start_idx가 마지막 인덱스인 경우까지 세줘야 모두 세어주는 것이 됨
  while(start_idx < input.length()) {
    // 구간 내부의 a와 b의 개수를 세어줌
    int a_cnt = 0;
    int b_cnt = 0;

    for(int i = 0; i < a_total_cnt; i++) {
      // 구간이 input 길이 내인 경우
      if(start_idx + i < input.length()) {
        if(input[start_idx + i] == 'a') {
          a_cnt++;
        } else {
          b_cnt++;
        }
      } else { // 구간이 input 길이 넘어가는 경우 처리
        if(input[i - (input.length() - start_idx)] == 'a') {
          a_cnt++;
        } else {
          b_cnt++;
        }
      }
    }

    // 이미 구간 안의 a의 개수가 전체 a의 개수와 같으면 끝! (0이 최소 횟수가 됨)
    if(a_cnt == a_total_cnt) {
      answer = 0;
      break;
    }

    // 내부의 b와 외부의 a를 맞교환 하면 해당 구역의 횟수가 된다
    // 최소만 기록
    if(answer > b_cnt) {
      answer = b_cnt;
    }

    // 다음 인덱스로 슬라이딩 윈도우 옮겨 줌!
    start_idx++;

    if(last_idx + 1 == input.length()) {
      last_idx = 0;
    } else {
      last_idx++;
    }
  }

  cout << answer;

  return 0;
}