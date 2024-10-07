#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

  int n = 0;
  int k = 0;

  scanf("%d %d\n", &n, &k);

  string input = "";

  getline(cin, input);

  int answer = 0;

  for(int i = 0; i < input.length(); i++) {
    bool ate = false;

    if(input[i] == 'P') {
      for(int j = k; j >= 1; j--) {
        if(i - j >= 0 && input[i - j] == 'H') {
          answer = answer + 1;
          input.replace(i - j, 1, "X");
          ate = true;
          break;;
        }
      }
      if(!ate) {
        for(int j = 1; j <= k; j++) {
          if(i + j < input.length() && input[i + j] == 'H') {
            answer = answer + 1;
            input.replace(i + j, 1, "X");
            break;
          }
        }
      }
    }
  }

  printf("%d", answer);

  return 0;
}