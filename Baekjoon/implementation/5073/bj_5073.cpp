#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int length[3] = { 0, };
  
  while(1) {
    scanf(" %d %d %d", &length[0], &length[1], &length[2]);

    if(length[0] == 0 && length[1] == 0 && length[2] == 0) {
      break;
    }

    int max_idx = max_element(length, length + 3) - length;

    int sum = 0;

    for(int i = 0; i < 3; i++) {
      if(i != max_idx) {
        sum += length[i];
      }
    }

    if(sum <= length[max_idx]) {
      printf("Invalid\n");
      continue;
    }

    if(length[0] == length[1] && length[0] == length[2]) {
      printf("Equilateral\n");
      continue;
    }

    if(length[0] == length[1] || length[0] == length[2] || length[1] == length[2]) {
      printf("Isosceles\n");
      continue;
    }

    printf("Scalene\n");
  }


  return 0;
}