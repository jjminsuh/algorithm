#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second) {
    return a.first < b.first;
  }

  return a.second < b.second;
}

int main() {

  // 입력
  int n = 0;

  cin >> n;

  vector<pair<int, int> > meetings(n);

  for(int i = 0; i < n; i++) {
    int start = 0;
    int end = 0;

    cin >> start >> end;

    meetings[i] = make_pair(start, end);
  }

  sort(meetings.begin(), meetings.end(), compare);

  int cnt = 1;
  pair<int, int> now_meeting = meetings[0];

  for(int i = 1; i < n; i++) {
    // 선택한 회의 끝나기 전에 시작하는 경우 continue;
    if(meetings[i].first < now_meeting.second) {
      continue;
    }

    cnt++;
    now_meeting = meetings[i];
  }

  cout << cnt;

  return 0;
}