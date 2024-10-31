#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare_words(pair<string, int> a, pair<string, int> b) {
  if(a.second == b.second) {
    if(a.first.length() == b.first.length()) {
      return a.first < b.first;
    }

    return a.first.length() > b.first.length();
  }
  
  return a.second > b.second;
}

int main() {

  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);

  int n = 0;
  int m = 0;
  string word = "";
  map<string, int> word_cnt;
  vector<pair<string, int> > word_book;

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    cin >> word;

    if(word.length() < m) {
      continue;
    }

    if(word_cnt.find(word) == word_cnt.end()) {
      word_cnt.insert({word, 1});
    } else {
      word_cnt[word]++;
    }
  }

  for(auto iter = word_cnt.begin(); iter != word_cnt.end(); iter++) {
    word_book.push_back(make_pair(iter->first, iter->second));
  }
  
  sort(word_book.begin(), word_book.end(), compare_words);

  for(int i = 0; i < word_book.size(); i++) {
    cout << word_book[i].first << "\n";
  }

  return 0;
}