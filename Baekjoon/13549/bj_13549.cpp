#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

  int n = 0;
  int k = 0;
  vector<int> visited;

  scanf("%d %d", &n, &k);

  visited.resize(100001);
  fill(visited.begin(), visited.end(), -1);

  queue<int> to_visit;

  to_visit.push(n);
  visited[n] = 0;

  while(!to_visit.empty()) {
    int front = to_visit.front();
    to_visit.pop();

    if(front == k) {
      break;
    }

    if(front - 1 >= 0) {
      if(visited[front - 1] == -1) {
        visited[front - 1] = visited[front] + 1;
        to_visit.push(front - 1);
      } else {
        if(visited[front - 1] > visited[front] + 1) {
          visited[front - 1] = visited[front] + 1;
          to_visit.push(front - 1);
        }
      }
    }

    if(front + 1 <= 200000) {
      if(visited[front + 1] == -1) {
        visited[front + 1] = visited[front] + 1;
        to_visit.push(front + 1);
      } else {
        if(visited[front + 1] > visited[front] + 1) {
          visited[front + 1] = visited[front] + 1;
          to_visit.push(front + 1);
        }
      }
    }

    if(2 * front <= 100000) {
      if(visited[2 * front] == -1) {
        visited[2 * front] = visited[front];
        to_visit.push(2 * front);
      } else {
        if(visited[2 * front] > visited[front]) {
          visited[2 * front] = visited[front];
          to_visit.push(2 * front);
        }
      }
    }
  }

  printf("%d", visited[k]);

  return 0;
}