#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);

  int input_tmp = 0;
  vector<bool> switches;

  for(int i = 0; i < n; i++) {
    scanf(" %d", &input_tmp);
    switches.push_back(input_tmp);
  }

  int student_num = 0;
  int gender = 0;
  int number = 0;
  vector<pair<int, int> > students;

  scanf(" %d", &student_num);

  for(int i = 0; i < student_num; i++) {
    scanf(" %d %d", &gender, &number);
    students.push_back(make_pair(gender, number));
  }

  for(int i = 0; i < student_num; i++) {
    if(students[i].first == 1) {
      int iter = students[i].second;

      while(iter <= switches.size()) {
        switches[iter - 1] = !switches[iter - 1];
        iter = iter + students[i].second;
      }

    } else {
      if(students[i].second - 1 == 0 || students[i].second - 1 == switches.size() - 1) {
        // printf("d %d\n", students[i].second - 1);
        switches[students[i].second - 1] = !switches[students[i].second - 1];
      } else {
        int iter = 1;
        int start = 0;
        int end = switches.size() - 1;

        while(1) {
          // 범위 넘어서는지 확인
          if(students[i].second - 1 - iter < 0 || students[i].second - 1 + iter > switches.size() - 1) {
            start = students[i].second - 1 - iter + 1;
            end = students[i].second - 1 + iter - 1;
            break;
          }

          // 대칭이 아닌 경우
          if(switches[students[i].second - 1 - iter] != switches[students[i].second - 1 + iter]) {
            start = students[i].second - 1 - iter + 1;
            end = students[i].second - 1 + iter - 1;
            break;
          }

          iter++;
        }

        for(int i = start; i <= end; i++) {
          switches[i] = !switches[i];
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    printf("%d ", (int)switches[i]);

    if((i + 1) % 20 == 0) {
      printf("\n");
    }
  }


  return 0;
}