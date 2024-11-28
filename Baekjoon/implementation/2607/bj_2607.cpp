#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> word_map(string word) {
  map<char, int> word_map;

  for(int i = 0; i < word.length(); i++) {
    if(word_map.find(word[i]) == word_map.end()) {
      word_map.insert(make_pair(word[i], 1));
    } else {
      word_map[word[i]]++;
    }
  }

  return word_map;
}

int main() {

  int n = 0;

  scanf("%d", &n);

  string first_word = "";
  string check_word = "";
  int answer = 0;

  cin >> first_word;

  map<char, int> first_word_map = word_map(first_word);

  for(int i = 0; i < n - 1; i++) {
    cin >> check_word;

    map<char, int> check_word_map = first_word_map;
    int cnt_add = 0;

    for(int j = 0; j < check_word.length(); j++) {
      if(check_word_map.find(check_word[j]) != check_word_map.end()) {
        if(check_word_map[check_word[j]] == 1) {
          check_word_map.erase(check_word[j]);
        } else {
          check_word_map[check_word[j]] -= 1;
        }
      } else {
        cnt_add++;
      }
    }

    if(check_word_map.empty()) {
      if(cnt_add <= 1) {
        answer++;
      }
    } else {
      int cnt_change = 0;

      for(auto iter = check_word_map.begin(); iter != check_word_map.end(); iter++) {
        cnt_change += iter -> second;
      }

      if(cnt_add <= 1 && cnt_change == 1) {
        answer++;
      }
    }
    
  }

  printf("%d", answer);

  return 0;
}