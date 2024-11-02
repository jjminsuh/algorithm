#include <iostream>
#include <vector>

using namespace std;

int min_val = 0;
int m = 0;
int n = 0;
vector<vector<int> > map;
vector<pair<int, int> > cctv;

void fill_cctv(int direction, int i, int j, int flag) {
  if(direction == 1) {
    int iter = j + 1;
    
    while(iter < m && map[i][iter] != 6) {
      if(map[i][iter] < 1) {
        if(flag == 1) {
          map[i][iter] += -1;
        }
        else {
          map[i][iter] += 1;
        }
      }
      
      iter++;
    }
  } else if(direction == 2) {
    int iter = i - 1;
    
    while(iter >= 0 && map[iter][j] != 6) {
      if(map[iter][j] < 1) {
        if(flag == 1) {
          map[iter][j] += -1;
        }
        else {
          map[iter][j] += 1;
        }
      }

      iter--;
    }
  } else if(direction == 3) {
    int iter = j - 1;
    
    while(iter >= 0 && map[i][iter] != 6) {
      if(map[i][iter] < 1) {
        if(flag == 1) {
          map[i][iter] += -1;
        }
        else {
          map[i][iter] += 1;
        }
      }

      iter--;
    }
  } else {
    int iter = i + 1;
    
    while(iter < n && map[iter][j] != 6) {
      if(map[iter][j] < 1) {
        if(flag == 1) {
          map[iter][j] += -1;
        }
        else {
          map[iter][j] += 1;
        }
      }
      
      iter++;
    }
  }

  return;
}

void find_blind_spot(int depth) {
  if(depth == cctv.size()) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(map[i][j] == 0) {
          cnt++;
        }
      }
    }

    if(min_val > cnt) {
      min_val = cnt;
    }

    return;
  }

  if(map[cctv[depth].first][cctv[depth].second] == 1) {
    for(int i = 1; i <= 4; i++) {
      fill_cctv(i, cctv[depth].first, cctv[depth].second, 1);
      find_blind_spot(depth + 1);
      fill_cctv(i, cctv[depth].first, cctv[depth].second, 0);
    }

  } else if(map[cctv[depth].first][cctv[depth].second] == 2) {
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);
  } else if(map[cctv[depth].first][cctv[depth].second] == 3) {
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);
  } else if(map[cctv[depth].first][cctv[depth].second] == 4) {
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);

    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);
  } else if(map[cctv[depth].first][cctv[depth].second] == 5) {
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 1);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 1);
    find_blind_spot(depth + 1);
    fill_cctv(1, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(2, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(3, cctv[depth].first, cctv[depth].second, 0);
    fill_cctv(4, cctv[depth].first, cctv[depth].second, 0);
  }
}

int main() {

  int input_tmp = 0;
  vector<int> row_tmp;

  scanf("%d %d", &n, &m);

  min_val = n * m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf(" %d", &input_tmp);
      row_tmp.push_back(input_tmp);

      if(input_tmp >= 1 && input_tmp <= 5) {
        cctv.push_back(make_pair(i, j));
      } 
    }

    map.push_back(row_tmp);
    row_tmp.clear();
  }

  find_blind_spot(0);

  printf("%d", min_val);

  return 0;
}