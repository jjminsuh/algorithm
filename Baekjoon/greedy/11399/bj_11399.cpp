#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;

  cin >> n;

  vector<int> time(n, 0);

  for(int i = 0; i < n; i++) {
    cin >> time[i];
  }

  sort(time.begin(), time.end());

  int answer = 0;
  int sum_up = 0;

  for(int i = 0; i < n; i++) {
    sum_up += time[i];
    answer += sum_up;
  }

  cout << answer;

  return 0;
}