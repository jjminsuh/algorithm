#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

  int n = 0;
  string inputTmp;
  vector< vector<char> > cookie;

  scanf("%d\n", &n);

  for(int i = 0; i < n; i++) {
    vector<char> row;
    getline(cin, inputTmp);

    for(int j = 0; j < n; j++) {
      row.push_back(inputTmp[j]);
    }

    cookie.push_back(row);
    row.clear();
  }

  int heartRow = 0;
  int heartCol = 0;
  int rowCheck[4] = {-1, 0, 1, 0};
  int colCheck[4] = {0, -1, 0, 1};

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int k = 0;

      if(i == n - 1 || j == n - 1 || i == 0 || j == 0) {
        continue;
      }

      for(k = 0; k < 4; k++) {
        if(cookie[i + rowCheck[k]][j + colCheck[k]] != '*') {
          break;
        }
      }

      if(k >= 4) {
          heartRow = i;
          heartCol = j;
      }
    }
  }

  int leftHand = 0;
  for(int i = heartCol - 1; i >= 0; i--) {
    if(cookie[heartRow][i] != '*') {
      break;
    }

    leftHand++;
  }

  int rightHand = 0;
  for(int i = heartCol + 1; i < n; i++) {
    if(cookie[heartRow][i] != '*') {
      break;
    }

    rightHand++;
  }

  int waist = 0;
  for(int i = heartRow + 1; i < n; i++) {
    if(cookie[i][heartCol] != '*') {
      break;
    }

    waist++;
  }

  int leftLeg = 0;
  for(int i = heartRow + waist + 1; i < n; i++) {
    if(cookie[i][heartCol - 1] != '*') {
      break;
    }

    leftLeg++;
  }

  int rightLeg = 0;
  for(int i = heartRow + waist + 1; i < n; i++) {
    if(cookie[i][heartCol + 1] != '*') {
      break;
    }

    rightLeg++;
  }

  printf("%d %d\n", heartRow + 1, heartCol + 1);
  printf("%d %d %d %d %d", leftHand, rightHand, waist, leftLeg, rightLeg);

  return 0;
}