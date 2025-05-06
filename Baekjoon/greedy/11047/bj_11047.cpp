#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n = 0;
  long long k = 0;

  cin >> n >> k;

  vector<int> value(n, 0);
  
  for(int i = 0; i < n; i++) {
    cin >> value[i];
  }

  int cnt = 0;
  int iter = n - 1;

  while(iter >= 0) {
    if(k / value[iter] > 0) {
      cnt += k / value[iter];
      k = k % value[iter];
    }

    iter--;
  }

  cout << cnt;

  return 0;
}