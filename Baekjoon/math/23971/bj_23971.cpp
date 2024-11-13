#include <iostream>

using namespace std;

int main() {

  int h = 0;
  int w = 0;
  int n = 0;
  int m = 0;

  scanf("%d %d %d %d", &w, &h, &n, &m);

  int w_iter = 0;
  int h_iter = 0;
  int answer = 0;

  while(h_iter < h) {
    w_iter = 0;

    while(w_iter < w) {
      answer++;
      w_iter += n + 1;
    }

    h_iter += m + 1;
  }

  printf("%d", answer);

  return 0;
}