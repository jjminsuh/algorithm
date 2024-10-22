#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int m = 0;
  int x = 0;
  int map[1001][1001] = { 0, };
  vector< vector<int> > edges;

  scanf("%d %d %d", &n, &m, &x);

  int startTmp = 0;
  int endTmp = 0;
  int distanceTmp = 0;

  edges.resize(n + 1);

  for(int i = 0; i < m; i++) {
    scanf(" %d %d %d", &startTmp, &endTmp, &distanceTmp);

    map[startTmp][endTmp] = distanceTmp;
    edges[startTmp].push_back(endTmp);
  }

  vector<int> results;

  for(int i = 1; i <= n; i++) {
    if(i == x) {
      results.push_back(0);
      continue;
    }

    queue<int> toVisit;
    int visited[1001] = { 0, };
    int answer = 0;

    fill(visited, visited + 1001, -1);

    toVisit.push(i);
    visited[i] = 0;

    while(!toVisit.empty()) {
      int front = toVisit.front();
      toVisit.pop();

      for(int j = 0; j < edges[front].size(); j++) {
        if(visited[edges[front][j]] == -1) {
          visited[edges[front][j]] = visited[front] + map[front][edges[front][j]];
          toVisit.push(edges[front][j]);
        } else {
          if(visited[edges[front][j]] > visited[front] + map[front][edges[front][j]]) {
            visited[edges[front][j]] = visited[front] + map[front][edges[front][j]];
            toVisit.push(edges[front][j]);
          }
        }
      }
    }

    answer = answer + visited[x];

    fill(visited, visited + 1001, -1);
    toVisit = queue<int> ();
    toVisit.push(x);
    visited[x] = 0;

    while(!toVisit.empty()) {
      int front = toVisit.front();
      toVisit.pop();

      for(int j = 0; j < edges[front].size(); j++) {
        if(visited[edges[front][j]] == -1) {
          visited[edges[front][j]] = visited[front] + map[front][edges[front][j]];
          toVisit.push(edges[front][j]);
        } else {
          if(visited[edges[front][j]] > visited[front] + map[front][edges[front][j]]) {
            visited[edges[front][j]] = visited[front] + map[front][edges[front][j]];
            toVisit.push(edges[front][j]);
          }
        }
      }
    }

    answer = answer + visited[i];

    results.push_back(answer);
  }

  int max = *max_element(results.begin(), results.end());
  
  printf("%d", max);

  return 0;
}