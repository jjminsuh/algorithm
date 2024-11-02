#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

  int n = 0;

  scanf("%d", &n);
  
  vector< pair<int, int> > column;
  pair<int, int> inputTmp;

  for(int i = 0; i < n; i++) {
    scanf(" %d %d", &inputTmp.first, &inputTmp.second);
    column.push_back(inputTmp);
  }

  sort(column.begin(), column.end());

  int maxHeight = 0;
  int maxHeightIdx = 0;

  for(int i = 0; i < column.size(); i++) {
    if(maxHeight < column[i].second) {
      maxHeight = column[i].second;
      maxHeightIdx = column[i].first;
    }
  }

  stack<int> leftStack;
  stack<int> rightStack;

  int answer = 0;

  int columnIter = 0;

  for(int i = column[0].first; i <= maxHeightIdx; i++) {
    if(leftStack.empty()) {
      leftStack.push(column[columnIter].second);
      columnIter++;
      continue;
    }

    int top = leftStack.top();

    if(i == column[columnIter].first) {
      if(leftStack.top() <= column[columnIter].second) {
        while(!leftStack.empty()) {
          answer = answer + leftStack.top();
          leftStack.pop();
        }

        leftStack.push(column[columnIter].second);
        columnIter++;
      } else {
        leftStack.push(leftStack.top());
        columnIter++;
      }
    } else {
      leftStack.push(leftStack.top());
    }
  }

  columnIter = column.size() - 1;

  for(int i = column[column.size() - 1].first; i >= maxHeightIdx; i--) {
    if(rightStack.empty()) {
      rightStack.push(column[columnIter].second);
      columnIter--;
      continue;
    }

    int top = rightStack.top();

    if(i == column[columnIter].first) {
      if(rightStack.top() <= column[columnIter].second) {
        while(!rightStack.empty()) {
          answer = answer + rightStack.top();
          rightStack.pop();
        }

        rightStack.push(column[columnIter].second);
        columnIter--;
      } else {
        rightStack.push(rightStack.top());
        columnIter--;
      }
    } else {
      rightStack.push(rightStack.top());
    }
  }

  answer = answer + maxHeight;

  printf("%d", answer);

  return 0;
}