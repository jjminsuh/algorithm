#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  string input = "";

  cin >> n;
  cin >> input;

  int r_count = 0;
  int b_count = 0;
  int conti_r = 0;
  int conti_b = 0;

  int iter = n - 1;
  
  if(input[iter] == 'R') {
    while(iter >= 0 && input[iter] == 'R') {
      r_count++;
      conti_r++;
      iter--;
    }
  } else {
    while(iter >= 0 && input[iter] == 'B') {
      b_count++;
      conti_b++;
      iter--;
    }
  }

  for(int i = iter; i >= 0; i--) {
    if(input[i] == 'R') {
      r_count++;
    } else {
      b_count++;
    }
  }

  int answer = min(r_count - conti_r, b_count - conti_b);

  r_count = 0;
  b_count = 0;
  conti_r = 0;
  conti_b = 0;

  iter = 0;
  
  if(input[iter] == 'R') {
    while(iter >= 0 && input[iter] == 'R') {
      r_count++;
      conti_r++;
      iter++;
    }
  } else {
    while(iter >= 0 && input[iter] == 'B') {
      b_count++;
      conti_b++;
      iter++;
    }
  }

  for(int i = iter; i < n; i++) {
    if(input[i] == 'R') {
      r_count++;
    } else {
      b_count++;
    }
  }

  answer = min(answer, min(r_count - conti_r, b_count - conti_b));

  printf("%d", answer);

  return 0;
}