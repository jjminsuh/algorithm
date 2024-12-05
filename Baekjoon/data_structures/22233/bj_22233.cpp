#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cout.tie(NULL);

  int n = 0;
  int m = 0;
  string input = "";
  unordered_set<string> words;

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    cin >> input;
    words.insert(input);
  }

  for(int i = 0; i < m; i++) {
    cin >> input;

    istringstream ss(input);
    string buffer;
    vector<string> used;

    while(getline(ss, buffer, ',')) {
      used.push_back(buffer);
    }
    
    for(int j = 0; j < used.size(); j++) {
      if(words.find(used[j]) != words.end()) {
        words.erase(used[j]);
      }
    }

    cout << words.size() << "\n";
  }

  
  return 0;
}