#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  int inputTmp = 0;
  vector<int> input;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf(" %d", &inputTmp);
    input.push_back(inputTmp);
  }

  int answer[11] = {0, };

  for(int i = 0; i < n; i++) {
    int cnt = 0;

    for(int j = 0; j < n; j++) {
      if(answer[j] == 0 && cnt == input[i]) {
          answer[j] = i + 1;
          break;
      }

      if(answer[j] == 0) {
        cnt = cnt + 1;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    printf("%d ", answer[i]);
  }

  return 0;
}