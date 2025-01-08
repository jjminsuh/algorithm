#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

int main() {

  int n = 0;
  int d = 0;
  int k = 0;
  int c = 0;

  deque<int> sushi;
  unordered_map<int, int> ate_sushi;

  int max_cnt = 0;

  cin >> n >> d >> k >> c;

  int input_tmp = 0;

  for(int i = 0; i < n; i++) {
    cin >> input_tmp;
    sushi.push_back(input_tmp);
  }

  // 앞에서부터 k개의 스시를 먹음
  for(int i = 0; i < k; i++) {
    if(ate_sushi.find(sushi[i]) != ate_sushi.end()) {
      ate_sushi[sushi[i]]++;
    } else {
      ate_sushi.insert(make_pair(sushi[i], 1));
    }
  }

  // 쿠폰 스시를 먹은 경우 쿠폰 스시를 제외한 종류만 count 함
  if(ate_sushi.find(c) != ate_sushi.end()) {
    max_cnt = ate_sushi.size() - 1;
  } else {
    max_cnt = ate_sushi.size();
  }

  // 스시를 연속으로 먹으므로 제일 앞의 것을 제외, 다음 스시를 먹은 경우 먹을 수 있는 스시 개수와 비교
  for(int i = 0; i < n; i++) {
    int front = sushi.front();
    sushi.pop_front();

    if(ate_sushi[front] == 1) {
      ate_sushi.erase(front);
    } else {
      ate_sushi[front]--;
    }

    sushi.push_back(front);

    if(ate_sushi.find(sushi[k - 1]) != ate_sushi.end()) {
      ate_sushi[sushi[k - 1]]++;
    } else {
      ate_sushi.insert(make_pair(sushi[k - 1], 1));
    }

    if(ate_sushi.find(c) != ate_sushi.end()) {
      if(max_cnt < ate_sushi.size() - 1) {
        max_cnt = ate_sushi.size() - 1;
      }
    } else {
      if(max_cnt < ate_sushi.size()) {
        max_cnt = ate_sushi.size();
      }
    }
  }

  printf("%d", max_cnt + 1);

  return 0;
}