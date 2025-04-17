#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

  string s;

  cin >> s;

  set<string> diff_strings;

  for(int i = 0; i < s.length(); i++) {
    for(int j = i + 1; j <= s.length(); j++) {
      diff_strings.insert(s.substr(i, j - i));
    }
  }

  cout << diff_strings.size();

  return 0;
}