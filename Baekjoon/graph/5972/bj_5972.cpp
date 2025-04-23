#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int m = 0;

  cin >> n >> m;

  vector< vector<pair<int, int> > > map(n + 1);

  for(int i = 0; i < m; i++) {
    int a = 0;
    int b = 0;
    int c = 0;

    cin >> a >> b >> c;

    // 엣지 정보를 함께 저장
    // 양방향 길이므로 양쪽 다 저장해준다.
    map[a].push_back(make_pair(b, c));
    map[b].push_back(make_pair(a, c));
  }

  queue< pair<int, int> > to_visit_edge;
  queue<int> visited_node;
  vector<int> min_feed(n + 1, -1);

  // 첫번째 노드 설정
  visited_node.push(1);
  min_feed[1] = 0;

  while(!visited_node.empty()) {
    int now_node = visited_node.front();
    visited_node.pop();

    for(int i = 0; i < map[now_node].size(); i++) {
      int next_node = map[now_node][i].first;
      int cost = map[now_node][i].second;

      // 근처 노드로 가는 최소 거리가 갱신되는 경우 다시 탐색할 노드에 추가
      // 갱신되지 않으면 그냥 지나친다
      if(min_feed[next_node] == - 1 || min_feed[next_node] > min_feed[now_node] + cost) {
        visited_node.push(next_node);
        min_feed[next_node] = min_feed[now_node] + cost;
      }
    }
  }

  cout << min_feed[n];

  return 0;
}