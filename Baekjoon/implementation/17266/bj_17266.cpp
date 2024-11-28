#include <iostream>

using namespace std;

int main() {

  int n = 0;
  int m = 0;
  int max = 0;

  scanf("%d", &n);
  scanf(" %d", &m);

  int now = 0;
  int place = 0;

  for(int i = 0; i < m; i++) {
    scanf(" %d", &place);

    if(i == 0) {
      if(place - now > max) {
        max = place - now;
      }

      now = place;
    } else {
      if((place - now) % 2 == 0) {
        if((place - now) / 2 > max) {
          max = (place - now) / 2;
        }
      } else {
        if(((place - now) / 2) + 1 > max) {
          max = ((place - now) / 2) + 1;
        }
      }

      now = place;
    }
  }

  if(n - now > max) {
    max = n - now;
  }

  printf("%d", max);

  return 0;
}