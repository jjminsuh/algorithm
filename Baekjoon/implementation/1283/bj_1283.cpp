#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {

  int n = 0;
  unordered_set<char> shortcuts;

  cin >> n;
  cin.ignore(); 

  for(int i = 0;  i < n; i++) {
    string option = "";
    // 공백까지 입력받는 경우 getline() 활용
    getline(cin, option);

    int index = 0;
    // 첫 글자가 단축어인 경우
    if(shortcuts.find(tolower(option[index])) == shortcuts.end()) {
      shortcuts.insert(tolower(option[index]));
      cout << "[" << option[index] << "]" << option.substr(1, option.length()) << "\n";
      continue;
    }

    bool has_find = false;
    // 첫 단어의 첫 글자가 이미 단축키인 경우 단어 단위로 다음 가능한 단축키 확인
    while(index < option.length()) {
      if(option[index] == ' ') {
        if(index + 1 < option.length()) {
          if(shortcuts.find(tolower(option[index + 1])) == shortcuts.end()) {
            shortcuts.insert(tolower(option[index + 1]));
            cout << option.substr(0, index + 1) << "[" << option[index + 1] << "]" << option.substr(index + 2, option.length()) << "\n";
            has_find = true;
            break;
          }
        }
      }

      index++;
    }

    if(has_find) {
      continue;
    }

    index = 1;
    has_find = false;
    // 모든 단어의 첫 글자가 사용중인경우 앞에서부터 비어있는 글자 찾기
    while(index < option.length()) {
      if(option[index] != ' ') {
          if(shortcuts.find(tolower(option[index])) == shortcuts.end()) {
            shortcuts.insert(tolower(option[index]));
            cout << option.substr(0, index) << "[" << option[index] << "]" << option.substr(index + 1, option.length()) << "\n";
            has_find = true;
            break;
          }
        }

      index++;
    }

    if(has_find) {
      continue;
    } else { 
      // 모든 경우가 안되는 경우
      cout << option << "\n";
    }

  }

  return 0;
}