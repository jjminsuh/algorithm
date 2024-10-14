// <<row, column>, hasDestoryWall>
  queue<pair<pair<int, int>, int> > toVisit;

  toVisit.push(make_pair(make_pair(0, 0), 0));
  visited[0][0] = 1;

  pair<pair<int, int>, int> front;
  int row = 0;
  int col = 0;
  int wall = 0;

  int checkRow[4] = {1, 0, -1, 0};
  int checkCol[4] = {0, 1, 0, -1};

  while(!toVisit.empty()) {
    front = toVisit.front();
    row = front.first.first;
    col = front.first.second;
    wall = front.second;

    toVisit.pop();

    for(int i = 0; i < 4; i++) {
      if(visited[row + checkRow[i]][col + checkCol[i]] == 0) {
        if(map[row + checkRow[i]][col + checkCol[i]] == 0) {
          toVisit.push(make_pair(make_pair(row + checkRow[i], col + checkCol[i]), wall));
          visited[row + checkRow[i]][col + checkCol[i]] = visited[row][col] + 1;
        } else {
          if(wall == 0) {
            toVisit.push(make_pair(make_pair(row + checkRow[i], col + checkCol[i]), 1));
            visited[row + checkRow[i]][col + checkCol[i]] = visited[row][col] + 1;
          }
        }
      }
    }
  }

  if(visited[n - 1][m - 1] != 0) {
    answer = visited[n - 1][m - 1];
  }

  printf("%d", 