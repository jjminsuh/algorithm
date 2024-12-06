#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
  
  int t = 0;

  cin >> t;

  for(int i = 0; i < t; i++) {
    int n = 0;
    int input = 0;
    vector<int> stock_price;

    cin >> n;

    for(int j = 0; j < n; j++) {
      cin >> input;
      stock_price.push_back(input);
    }

    long long cost = 0;
    int max = 0;

    // 뒤에서부터 max 찾기 -> 시간 초과에 걸리지 않기 위해!
    // 다음 max가 나타나기 전까지는 해당 max 가격에 파는것이 최고 이익을 냄!
    for(int j = n - 1; j >= 0; j--) {
      if(stock_price[j] > max) {
        max = stock_price[j];
      } else {
        cost = cost - stock_price[j] + max;
      }
    }

    cout << cost << "\n";
    
  }

  return 0;
}