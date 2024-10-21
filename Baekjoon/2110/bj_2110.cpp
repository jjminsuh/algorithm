#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int c = 0;
  int inputTmp = 0;
  vector<int> houses;

  scanf("%d %d", &n, &c);

  for(int i = 0; i < n; i++) {
    scanf(" %d", &inputTmp);
    houses.push_back(inputTmp);
  }

  sort(houses.begin(), houses.end());

  int start = 1;
  int end = houses[n - 1] - houses[0];
  int answer = 0;
  
  while(start <= end) {
    int mid = (start + end) / 2;

    int prevIdx = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++) {
      if(houses[i] - houses[prevIdx] >= mid) {
        prevIdx = i;
        cnt++;
      }
    }

    if(cnt >= c) {
      if(answer < mid) {
        answer = mid;
      }

      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  printf("%d", answer);

  return 0;
}