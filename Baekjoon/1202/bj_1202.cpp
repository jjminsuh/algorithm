#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare_pair(pair<int, int> a, pair<int, int> b) {
  if(a.first == b.first) {
    return a.second < b.second;
  }

  return a.first < b.first;
}

int main() {

  int n = 0;
  int k = 0;
  int m = 0;
  int v = 0;
  int bag = 0;

  scanf("%d %d", &n, &k);

  vector<pair<int, int> > objects;

  for(int i = 0; i < n; i++) {
    scanf(" %d %d", &m, &v);
    objects.push_back(make_pair(m, v));
  }

  vector<int> bags;

  for(int i = 0; i < k; i++) {
    scanf(" %d", &bag);
    bags.push_back(bag);
  }

  sort(objects.begin(), objects.end(), compare_pair);

  sort(bags.begin(), bags.end());

  long long answer = 0;
  priority_queue<int> values;

  int iter = 0;

  for(int i = 0; i < k; i++) {
    for(int j = iter; j < n; j++) {
      if(objects[iter].first > bags[i]) {
        break;
      }

      if(objects[iter].first <= bags[i]) {
        values.push(objects[iter].second);
        iter++;
      }
    }
    
    if(!values.empty()) {
      answer += values.top();
      values.pop();
    }
  }

  printf("%lld", answer);

  return 0;
}