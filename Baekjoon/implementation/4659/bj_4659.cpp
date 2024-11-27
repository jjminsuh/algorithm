#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  string input = "";
  char vouls[5] = {'a', 'e', 'i', 'o', 'u'};


  while(true) {
    cin >> input;

    if(input == "end") {
      break;
    }

    bool hasVoul = false;
    bool firstIsVoul = false;
    bool secondIsVoul = false;
    bool thirdIsVoul = false;
    bool isOk = true;

    if(input[0] == input[1]) {
      if(input[0] != 'e' && input[0] != 'o') {
        isOk = false;
      }
    }

    for(int iter = 0; iter < 5; iter++) {
      if(input[0] == vouls[iter]) {
        hasVoul = true;
        firstIsVoul = true;
      }

      if(input[1] == vouls[iter]) {
        hasVoul = true;
        secondIsVoul = true;
      }
    }

    for(int i = 2; i < input.length(); i++) {
      if(input[i - 1] == input[i]) {
        if(input[i] != 'e' && input[i] != 'o') {
          isOk = false;
          break;
        }
      }

      for(int iter = 0; iter < 5; iter++) {
        if(input[i] == vouls[iter]) {
          hasVoul = true;
          thirdIsVoul = true;
        }
      }

      if(firstIsVoul == secondIsVoul) {
        if(secondIsVoul == thirdIsVoul) {
          isOk = false;
          break;
        }
      }

      firstIsVoul = secondIsVoul;
      secondIsVoul = thirdIsVoul;
      thirdIsVoul = false;
    }

    if(!hasVoul) {
      isOk = false;
    }

    if(isOk) {
      printf("<%s> is acceptable.\n", input.c_str());
    } else {
      printf("<%s> is not acceptable.\n", input.c_str());
    }
  }

  return 0;
}