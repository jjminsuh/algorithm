#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  long long inputTmp = 0;
  vector<long long> distance;
  vector<long long> price;

  scanf("%d", &n);

  for(int i = 0; i < n - 1; i++) {
    scanf(" %lld", &inputTmp);
    distance.push_back(inputTmp);
  }

  for(int i = 0; i < n; i++) {
    scanf(" %lld", &inputTmp);
    price.push_back(inputTmp);
  }

  long long cost = 0;

  int now = 0;
  int iter = now + 1;

  while(iter < n) {
    if(price[now] < price[iter]) {
      cost = cost + (price[now] * distance[iter - 1]);
      iter++;

      continue;
    }

    cost = cost + (price[now] * distance[iter - 1]);
    now = iter;
    iter = now + 1;
  }

  printf("%lld", cost);

  return 0;
}