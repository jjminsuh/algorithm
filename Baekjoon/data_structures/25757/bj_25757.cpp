#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

  int n = 0;
  char game = ' ';
  set<string> played;
  string player = "";
  int max = 0;
  int cnt = 0;
  int answer = 0;

  scanf("%d %c", &n, &game);

  if(game == 'Y') {
    max = 1;
  } else if(game == 'F') {
    max = 2;
  } else {
    max = 3;
  }

  for(int i = 0; i < n; i++) {
    cin >> player;

    if(played.find(player) == played.end()) {
      played.insert(player);

      if(cnt == max) {
        answer++;
        cnt = 0;
      }

      cnt++;
    }
  }

  if(cnt == max) {
    answer++;
    cnt = 0;
  }

  printf("%d", answer);

  return 0;
}