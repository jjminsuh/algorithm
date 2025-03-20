#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int t = 0;

  cin >> t;

  for(int i = 0; i < t; i++) {
    string w;
    int k;

    cin >> w;
    cin >> k;

    map<char, vector<int>> characters;

    int min_length = -1;
    int max_length = 0;

     // k == 1인 경우 처리
    // 무조건 min, max length가 1이다.
    if(k == 1) {
      min_length = 1;
      max_length = 1;

      cout << min_length << " " << max_length << "\n";

      continue;
    }

    // 입력 단어를 순회하며 알파벳 별로 개수를 입력 받는다
    for(int i = 0; i < w.length(); i++) {
      if(characters.find(w[i]) != characters.end()) {
        characters[w[i]].push_back(i);
      } else {
        vector<int> character_idx = {i};
        characters.insert(make_pair(w[i], character_idx));
      }
    }

    // 문자열 첫 번째 문자부터 탐색 -> k개 이하인 문자는 넘어감
    for(int i = 0; i < w.length(); i++) {
      if(characters[w[i]].size() >= k) {
        int cnt = 1;
        for(int j = i + 1; j < w.length(); j++) {
          if(w[i] == w[j]) {
            cnt++;
          }

          if(cnt == k) {
            if(min_length == -1 || min_length > j - i + 1) {
              min_length = j - i + 1;
            }

            if(max_length < j - i + 1) {
              max_length = j - i + 1;
            }

            break;
          }
        }
      }
    }

    if(min_length == -1) {
      cout << min_length << "\n";
    } else {
      cout << min_length << " " << max_length << "\n";
    }
  }
}