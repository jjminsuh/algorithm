#include <iostream>
#include <queue>

using namespace std;

int main() {

  int n = 0;
  int k = 0;

  scanf("%d %d", &n, &k);

  int visited[100001] = { 0, };
  fill(visited, visited + 100001, -1);

  int answer = 0;
  int front = 0;
  int MAX_VAL = 100000;

  if(n >= k) {
    answer = n - k;
    printf("%d", answer);
    return 0;
  }

  queue<int> toVisit;

  toVisit.push(n);
  visited[n] = 0;

  while(!toVisit.empty()) {
    front = toVisit.front();
    toVisit.pop();

    if(front == k) {
      break;
    }

    if(front - 1 <= MAX_VAL && front - 1 >= 0) {
      if(visited[front - 1] == -1) {
        toVisit.push(front - 1);
        visited[front - 1] = visited[front] + 1;
      }
    }
    
    if(front + 1 <= MAX_VAL && front + 1 >= 0) {
      if(visited[front + 1] == -1) {
        toVisit.push(front + 1);
        visited[front + 1] = visited[front] + 1;
      }
    }

    if(2 * front <= MAX_VAL && 2 * front >= 0) {
      if(visited[2 * front] == -1) {
        toVisit.push(2 * front);
        visited[2 * front] = visited[front] + 1;
      }
    }
  }

  answer = visited[k];

  printf("%d", answer);

  return 0;
}