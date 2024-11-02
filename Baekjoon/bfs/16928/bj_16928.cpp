#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {

  int n = 0;
  int m = 0;
  int tmp1 = 0;
  int tmp2 = 0;

  map<int, int> ladder_snake;

  int board[101] = { 0, };

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n + m; i++) {
    scanf(" %d %d", &tmp1, &tmp2);

    ladder_snake.insert(make_pair(tmp1, tmp2));
  }

  queue<int> to_visit;

  to_visit.push(1);
  board[1] = 0;

  while(!to_visit.empty()) {
    int front = to_visit.front();
    to_visit.pop();

    if(ladder_snake.find(front) != ladder_snake.end()) {
      to_visit.push(ladder_snake[front]);

      if(board[ladder_snake[front]] == 0) {
        board[ladder_snake[front]] = board[front];
        to_visit.push(ladder_snake[front]);
      } else {
        if(board[ladder_snake[front]] > board[front]) {
          board[ladder_snake[front]] = board[front];
          to_visit.push(ladder_snake[front]);
        }
      }

      continue;
    }

    for(int i = 1; i <= 6; i++) {
      if(front + i <= 100) {
        if(board[front + i] == 0) {
          board[front + i] = board[front] + 1;
          to_visit.push(front + i);
        } else {
          if(board[front + i] > board[front] + 1) {
            board[front + i] = board[front] + 1;
            to_visit.push(front + i);
          }
        }
      }
    }
  }

  printf("%d", board[100]);

  return 0;
}