#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_pair(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if(a.first.second == b.first.second) {
    if(a.first.first == b.first.first) {
      return a.second < b.second;
    }

    return a.first.first < b.first.first;
  }

  return a.first.second < b.first.second;
}

int main() {

  int n = 0;
  int d = 0;

  cin >> n >> d;

  vector<pair<pair<int, int>, int> > shortcut;

  for(int i = 0; i < n; i++) {
    int start = 0;
    int end = 0;
    int distance = 0;

    cin >> start >> end >> distance;

    shortcut.push_back(make_pair(make_pair(start, end), distance));
  }

  sort(shortcut.begin(), shortcut.end(), compare_pair);

  vector<int> min_dis(d + 1);
  int iter = 0;

  for(int i = 1; i <= d; i++) {
    int min_shrotcut = d;

    while(iter < n && shortcut[iter].first.second <= i) {
      if(shortcut[iter].first.second == i) {
        min_shrotcut = min(min_shrotcut, min_dis[shortcut[iter].first.first] + shortcut[iter].second);
      }

      iter++;
    }

    min_dis[i] = min(min_dis[i - 1] + 1, min_shrotcut);
  }

  printf("%d", min_dis[d]);

  return 0;
}