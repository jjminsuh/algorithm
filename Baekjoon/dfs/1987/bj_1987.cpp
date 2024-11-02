#include <iostream>
#include <vector>

using namespace std;

int MAX = 0;
vector<vector<char> > map;
int rowCheck[4] = {0, 1, 0, -1};
int colCheck[4] = {1, 0, -1, 0};
int visited[20][20] = { 0, };

void dfs(int depth, int *used_alphabet, int r, int c, int x, int y) {
  if(used_alphabet[map[x][y] - 'A'] != 0) {
      if(MAX < depth - 1) {
        MAX = depth - 1;
      }
      return;
  }

  used_alphabet[map[x][y] - 'A'] = 1;

  for(int i = 0; i < 4; i++) {
    if(x + rowCheck[i] < 0 || x + rowCheck[i] >= r || y + colCheck[i] < 0 || y + colCheck[i] >= c) {
      continue;
    }

    if(visited[x + rowCheck[i]][y + colCheck[i]] == 0) {
      visited[x + rowCheck[i]][y + colCheck[i]] = 1;

      dfs(depth + 1, used_alphabet, r, c, x + rowCheck[i], y + colCheck[i]);

      visited[x + rowCheck[i]][y + colCheck[i]] = 0;
    }
  }

  used_alphabet[map[x][y] - 'A'] = 0;

  if(MAX < depth) {
    MAX = depth;
  }

  return;
}

int main() {

  int r = 0;
  int c = 0;
  string input = "";
  
  vector<char> rowTmp;

  scanf("%d %d\n", &r, &c);

  for(int i = 0; i < r; i++) {
    getline(cin, input);
  
    for(int j = 0; j < c; j++) {
      rowTmp.push_back(input[j]);
    }

    map.push_back(rowTmp);
    rowTmp.clear();
    input = "";
  }
  
  int used_alphabet[26] = { 0, };
  visited[0][0] = 1;

  dfs(1, used_alphabet, r, c, 0, 0);

  printf("%d", MAX);

  return 0;
}