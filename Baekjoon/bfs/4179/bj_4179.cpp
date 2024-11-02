#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int r = 0;
  int c = 0;

  scanf("%d %d\n", &r, &c);

  string input_tmp = "";
  vector<vector<char> > map;
  vector<char> row_tmp;
  queue<pair<int, int> > now_person;
  queue<pair<int, int> > now_fire;
  queue<pair<int, int> > next_person;
  queue<pair<int, int> > next_fire;
  int fire_visited[1000][1000] = {0, };
  int person_visited[1000][1000] = {0, };
  int r_check[4] = {0, -1, 0, 1};
  int c_check[4] = {-1, 0, 1, 0};

  for(int i = 0; i < r; i++) {
    getline(cin, input_tmp);

    for(int j = 0; j < input_tmp.length(); j++) {
      if(input_tmp[j] == 'J') {
        next_person.push(make_pair(i, j));
        person_visited[i][j] = 1;
        row_tmp.push_back('.');
        continue;
      }

      if(input_tmp[j] == 'F') {
        next_fire.push(make_pair(i, j));
        fire_visited[i][j] = 1;
        row_tmp.push_back(input_tmp[j]);
        continue;
      }

      row_tmp.push_back(input_tmp[j]);
    }

    map.push_back(row_tmp);
    row_tmp.clear();
  }

  while(!next_person.empty()) {
    now_person = next_person;
    now_fire = next_fire;

    next_person = queue<pair<int, int> >();
    next_fire = queue<pair<int, int> >();

    while(!now_fire.empty()) {
      pair<int, int> front = now_fire.front();
      int row = front.first;
      int col = front.second;
      now_fire.pop();

      for(int i = 0; i < 4; i++) {
        if(row + r_check[i] >= 0 && row + r_check[i] < r && col + c_check[i] >= 0 && col + c_check[i] < c) {
          if(fire_visited[row + r_check[i]][col + c_check[i]] == 0) {
            if(map[row + r_check[i]][col + c_check[i]] == '.') {
              next_fire.push(make_pair(row + r_check[i], col + c_check[i]));
              fire_visited[row + r_check[i]][col + c_check[i]] = 1;
              map[row + r_check[i]][col + c_check[i]] = 'F';
            }
          }
        }
      }
    }

    while(!now_person.empty()) {
      pair<int, int> front = now_person.front();
      int row = front.first;
      int col = front.second;
      now_person.pop();

      for(int i = 0; i < 4; i++) {
        if(row + r_check[i] < 0 || row + r_check[i] >= r || col + c_check[i] < 0 || col + c_check[i] >= c) {
          printf("%d", (person_visited[row][col] + 1) - 1);
          return 0;
        }
        
        if(person_visited[row + r_check[i]][col + c_check[i]] == 0) {
          if(map[row + r_check[i]][col + c_check[i]] == '.') {
            next_person.push(make_pair(row + r_check[i], col + c_check[i]));
            person_visited[row + r_check[i]][col + c_check[i]] = person_visited[row][col] + 1;
          }
        }
      }
    }
  }

  printf("IMPOSSIBLE");

  return 0;
}