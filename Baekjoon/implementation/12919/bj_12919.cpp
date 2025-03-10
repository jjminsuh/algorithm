#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_possible = false;

// s에서 t를 만들 수 있는지 확인하면 시간 초과가 뜸!
// 거꾸로 t에서 s로 돌아갈 수 있는지 확인하는 방법을 사용해야 함!
void check_string(string s, string t) {
  if(is_possible) {
    return;
  }

  if(s.length() > t.length()) {
    return;
  }

  if(s.length() == t.length()) {
    if(s == t) {
      is_possible = true;
    }
    return;
  }

  // 마지막이 A이면 A 붙이기를 했는지 확인 위해 A를 뗀다.
  if(t[t.length() - 1] == 'A') {
    string new_t = t.substr(0, t.length() - 1);
    check_string(s, new_t);
  }

  // 앞이 B 이면 B 붙이기 + 뒤집기를 했는지 확인
  if(t[0] == 'B') {
    string new_t = t.substr(1, t.length());
    reverse(new_t.begin(), new_t.end());
    check_string(s, new_t);
  }
}

int main() {

  string s;
  string t;

  cin >> s >> t;

  check_string(s, t);

  if(is_possible) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}