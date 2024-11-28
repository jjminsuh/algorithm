#include <iostream>

using namespace std;

int main() {
  
  string input = "";

  cin >> input;

  int min_num = 1;
  int iter = 0;

  while(iter < input.length()) {
    string min_num_string = to_string(min_num);

    for(int i = 0; i < min_num_string.length(); i++) {
      if(iter < input.length()) {
        if(min_num_string[i] == input[iter]) {
          iter++;
        }
      } else {
        printf("%d", min_num);
        return 0;
      }
    }

    min_num++;
  }

  printf("%d", min_num - 1);
  
  return 0;
}