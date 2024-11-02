#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

  int n = 0;
  int input_tmp = 0;
  vector<int> input;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf(" %d", &input_tmp);
    input.push_back(input_tmp);
  }

  stack<pair<int, int> > buildings;
  vector<int> answers;
  int iter = input.size() - 1;

  answers.resize(n);

  buildings.push(make_pair(input[iter], iter));
  iter = iter - 1;

  while(iter >= 0) {
    while(!buildings.empty()) {
      pair<int, int> top = buildings.top();

      if(input[iter] <= top.first) {
        break;
      }

      answers[top.second] = iter + 1;;
      buildings.pop();
    }

    buildings.push(make_pair(input[iter], iter));
    iter = iter - 1;
  }

  while(!buildings.empty()) {
    pair<int, int> top = buildings.top();
    buildings.pop();
    answers[top.second] = 0;
  }

  for(int i = 0; i < n; i++) {
    printf("%d ", answers[i]);
  }

  return 0;
}