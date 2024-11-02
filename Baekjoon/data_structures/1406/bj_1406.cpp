#include <iostream>
#include <string>
#include <queue>

using namespace std;

deque<char> words_front;
deque<char> words_back;

int main() {

  ios_base::sync_with_stdio(false); 

  cin.tie(NULL); 
  cout.tie(NULL);

  string input;

  // getline(cin, input);
  cin >> input;

  for(int i = 0; i < input.size(); i++) {
    words_front.push_back(input[i]);
  }

  int m = 0;
  char command;
  char letter;

  // scanf(" %d", &m);
  cin >> m;

  for(int i = 0; i < m; i++) {
    // scanf(" %c", &command);
    cin >> command;

    if(command == 'L') {
      if(!words_front.empty()) {
        int back = words_front.back();

        words_front.pop_back();
        words_back.push_front(back);
      }
    } else if(command == 'D') {
      if(!words_back.empty()) {
        int front = words_back.front();

        words_back.pop_front();
        words_front.push_back(front);
      }
    } else if(command == 'B') {
      if(!words_front.empty()) {
        words_front.pop_back();
      }
    } else if(command == 'P') {
      // scanf(" %c", &letter);
      cin >> letter;

      words_front.push_back(letter);
    }
  }

  string answer = "";

  for(int i = 0; i < words_front.size(); i++) {
    answer += words_front[i];
  }

  for(int i = 0; i < words_back.size(); i++) {
    answer += words_back[i];
  }

  // printf("%s", answer.c_str());
  cout << answer;

  return 0;
}