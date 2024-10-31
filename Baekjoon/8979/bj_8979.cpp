#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare_medal(pair<int, tuple<int, int, int> > a, pair<int, tuple<int, int, int> > b) {
  if(get<0>(a.second) == get<0>(b.second)) {
    if(get<1>(a.second) == get<1>(b.second)) {
      return get<2>(a.second) > get<2>(b.second);
    }

    return get<1>(a.second) > get<1>(b.second);
  }

  return get<0>(a.second) > get<0>(b.second);
}

int main() {

  int n = 0;
  int k = 0;

  scanf("%d %d", &n, &k);

  vector<pair<int, tuple<int, int, int> > > medals;
  int country = 0;
  int gold = 0;
  int silver = 0;
  int bronze = 0;

  for(int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &country, &gold, &silver, &bronze);

    medals.push_back(make_pair(country, make_tuple(gold, silver, bronze)));
  }


  sort(medals.begin(), medals.end(), compare_medal);

  int answer = 0;
  int count = 0;

  for(int i = 0; i < n; i++){
    if(i == 0) {
      answer = 1;
    } else {
      if(compare_medal(medals[i - 1], medals[i])) {
        answer = answer + count + 1;
        count = 0;
      } else {
        count++;
      }
    }

    if(medals[i].first == k) {
      break;
    } 
  }

  printf("%d", answer);

  return 0;
}