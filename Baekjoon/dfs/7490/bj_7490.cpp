#include <iostream>
#include <deque>

using namespace std;

void dfs(int depth, int n, int result, deque<char> operations) {
  // result 계산
  int oper_result = result;
  if(operations.size() > 0) {
    if(operations.back() == ' ') {
      int res = 0;
      int number = depth - 1;
      int mul = 1;
      char oper = ' ';

      for(int i = operations.size() - 1; i >= 0; i--) {
        if(operations[i] != ' ') {
          oper = operations[i];
          break;
        }
    
        res += number * mul;
        number--;
        mul *= 10;
      }

      if(oper == '-') {
        oper_result = result + res - (res * 10 + depth);
      } else {
        oper_result = result - res + (res * 10 + depth);
      }
    
    } else if(operations.back() == '+') {
      oper_result = result + depth;
    } else {
      oper_result = result - depth;
    }
  }

  if(depth == n) {
    if(oper_result == 0) {
      for(int i = 0; i < n - 1; i++) {
        cout << i + 1 << operations[i];
      }

      cout << n << "\n";
    }

    return;
  }

  // dfs 돌리기
  // 공백
  operations.push_back(' ');
  dfs(depth + 1, n, oper_result, operations);
  operations.pop_back();

  // 더하기
  operations.push_back('+');
  dfs(depth + 1, n, oper_result, operations);
  operations.pop_back();

  // 빼기
  operations.push_back('-');
  dfs(depth + 1, n, oper_result, operations);
  operations.pop_back();
}

int main() {

  int t = 0;
  int n = 0;

  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> n;

    deque<char> operations;

    dfs(1, n, 1, operations);

    cout << "\n";
  }

  return 0;
}