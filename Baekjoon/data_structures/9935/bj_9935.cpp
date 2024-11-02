#include <iostream>
#include <string>
#include <stack>
#include <deque>

using namespace std;

int main() {

  string input = "";
  string bomb = "";
  deque<char> bomb_letters;
  
  getline(cin, input);
  getline(cin, bomb);

  int bomb_length = bomb.length();

  for(int i = 0; i < bomb_length; i++) {
    bomb_letters.push_back(bomb[i]);
  }

  stack<char> save_letters;
  deque<char> check;
  string answer;

  for(int i = 0; i < input.length(); i++) {
    if(check.size() < bomb_length) {
      check.push_back(input[i]);
      continue;
    }

    if(check.size() == bomb_length) {
      if(check == bomb_letters) {
        check.clear();

        int iter = 0;
        
        while(!save_letters.empty() && iter < bomb_length - 1) {
          check.push_front(save_letters.top());
          save_letters.pop();
          iter++;
        }
      } else {
        save_letters.push(check.front());
        check.pop_front();
      }

      check.push_back(input[i]);
    }
  }

  if(check == bomb_letters) {
    check.clear();
  }

  while(!save_letters.empty()) {
    check.push_front(save_letters.top());
    save_letters.pop();
  }

  while(!check.empty()) {
    answer += check.front();
    check.pop_front();
  }

  if(answer == "") {
    printf("FRULA");
  } else {
    printf("%s", answer.c_str());
  }
  

  return 0;
}