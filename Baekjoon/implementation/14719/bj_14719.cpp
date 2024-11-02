#include <iostream>
#include <vector>

using namespace std;

int main() {

  int h = 0;
  int w = 0;

  scanf("%d %d", &h, &w);

  vector<int> heights;
  int input_tmp = 0;

  for(int i = 0; i < w; i++) {
    scanf(" %d", &input_tmp);
    heights.push_back(input_tmp);
  }

  int iter = 0;

  int answer = 0;
  int water = 0;

  int now = iter;

  while(iter < heights.size()) {
    if(heights[now] > heights[iter]) {
      water += heights[now] - heights[iter];
    } else {
      answer += water;
      water = 0;
      now = iter;
    }

    iter++;
  }

  iter = heights.size() - 1;
  now = heights[iter];
  water = 0;

  while(iter >= 0) {
    if(now >= heights[iter]) {
      water += now - heights[iter];
    } else {
      answer += water;
      water = 0;
      now = heights[iter];
    }

    iter--;
  }

  printf("%d", answer);

  return 0;
}