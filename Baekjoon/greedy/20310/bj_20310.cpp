#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {

  string input = "";

  cin >> input;

  int cnt_one = 0;
  int cnt_zero = 0;

  for(int i = 0; i < input.length(); i++) {
    if(input[i] == '0') {
      cnt_zero++;
    }

    if(input[i] == '1') {
      cnt_one++;
    }
  }

  string answer = "";
  deque<char> remaining;

  // 1은 앞에서부터 지우고 0은 뒤에서부터 지우면 사전순으로 가장 첫번째 값이 됨.
  int deleted = 0;

  for(int i = 0; i < input.length(); i++) {
    if(input[i] == '1') {
      if(deleted < cnt_one / 2) {
        deleted++;
        continue;
      } else {
        remaining.push_back(input[i]);
      }
    } else {
      remaining.push_back(input[i]);
    }
  }

  deleted = 0;

  while(!remaining.empty()) {
    char back = remaining.back();
    remaining.pop_back();

    if(back == '0') {
      if(deleted < cnt_zero / 2) {
        deleted++;
        continue;
      } else {
        answer = back + answer;
      }
    } else {
      answer = back + answer;
    }
  }

  printf("%s", answer.c_str());

  return 0;
}