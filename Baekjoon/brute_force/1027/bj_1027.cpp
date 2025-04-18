#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50

using namespace std;

long long buildings[MAX];

bool can_see(pair<int, long long> building_l, pair<int, long long> building_r) {
  for(int i = building_l.first + 1; i < building_r.first; i++) {
    long long height = buildings[i];

    // double 계산하지 않도록 수식 변환
    if(height * (building_l.first - building_r.first) <= (building_l.second * (building_l.first - building_r.first)) + ((i - building_l.first) * (building_l.second - building_r.second))) {
      return false;
    }
  }

  return true;
}

int main() {

  int n = 0;

  cin >> n;

  vector<int> see_buildings_cnt(n, 0);

  for(int i = 0; i < n; i++) {
    cin >> buildings[i];
  }

  for(int i = 0; i < n; i++) {
    // 내 뒤에만 탐색
    for(int j = i + 1; j < n; j++) {
      // 보이는지 확인
      if(can_see(make_pair(i, buildings[i]), make_pair(j, buildings[j]))) {
        see_buildings_cnt[i]++;
        see_buildings_cnt[j]++;
      }
    }
  }

  cout << *max_element(see_buildings_cnt.begin(), see_buildings_cnt.end());

  return 0;
}