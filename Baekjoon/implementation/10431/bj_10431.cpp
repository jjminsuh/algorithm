#include <iostream>

using namespace std;

int main() {

  int p = 0;

  int STUDENT_CNT = 20;

  scanf("%d", &p);

  for(int i = 0; i < p; i++) {
    int t = 0;
    int input_tmp = 0;

    int order[20] = { 0, };
    int cnt = 0;

    scanf("%d", &t);

    for(int j = 0; j < STUDENT_CNT; j++) {
      scanf(" %d", &input_tmp);

      if(j == 0) {
        order[j] = input_tmp;
        continue;
      }

      if(order[j - 1] <= input_tmp) {
        order[j] = input_tmp;
      } else {
        int idx = j - 1;
        
        while(order[idx] > input_tmp) {
          if(idx < 0) {
            break;
          }

          order[idx + 1] = order[idx];
          idx--;
          cnt++;
        }

        order[idx + 1] = input_tmp;
      }
    }

    printf("%d %d\n", t, cnt);
  }

  return 0;
}