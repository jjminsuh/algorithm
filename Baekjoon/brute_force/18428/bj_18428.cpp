#include <iostream>
#include <vector>

using namespace std;

bool is_possible = false;
vector<vector<char> > map;

void dfs(int depth, int n) {
  if(depth == 3) {

  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(map[i][j] == 'X') {
        
      }
    }
  }
}

int main() {

  int n = 0;

  cin >> n;

  map.assign(n, vector<char>(n, ' '));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  cout << "\n";

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << map[i][j] << " ";
    }

    cout << "\n";
  }

  return 0;
}