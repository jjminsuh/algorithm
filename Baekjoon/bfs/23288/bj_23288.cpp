#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;

struct dice {
    int top;
    int right;
    int up;
};

int search_point(int r, int c, int num, int n, int m) {
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1));
    int check_r[4] = {0, 0, 1, -1};
    int check_c[4] = {1, -1, 0, 0};

    int cnt = 1;

    queue<pair<int, int>> to_visit;
    to_visit.push(make_pair(r, c));
    visited[r][c] = true;

    while(!to_visit.empty()) {
        pair<int, int> front = to_visit.front();
        to_visit.pop();

        for(int i = 0; i < 4; i++) {
            if(front.first + check_r[i] > 0 && front.first + check_r[i] <= n && front.second + check_c[i] > 0 && front.second + check_c[i] <= m) {
                if (map[front.first + check_r[i]][front.second + check_c[i]] == num){
                    if (!visited[front.first + check_r[i]][front.second + check_c[i]]){
                        to_visit.push(make_pair(front.first + check_r[i], front.second + check_c[i]));
                        visited[front.first + check_r[i]][front.second + check_c[i]] = true;
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt;
}


int solution(int n, int m, int k) {
    int points = 0;
    int move_r[4] = {0, 1, 0, -1};
    int move_c[4] = {1, 0, -1, 0};
    // 동남서북 순서대로
    int dir = 0;

    int r = 1;
    int c = 1;
    
    dice dice_position;
    dice_position.top = 1;
    dice_position.right = 3;
    dice_position.up = 2;

    // k번 주사위 이동
    for(int i = 0; i < k; i++) {
        // dir 방향으로 이동
        // dir 방향으로 이동할 수 있는지 확인
        if(r + move_r[dir] > 0 && r + move_r[dir] <= n && c + move_c[dir] > 0 && c + move_c[dir] <= m) {
            r = r + move_r[dir];
            c = c + move_c[dir];
        } else {
            if(dir == 0 || dir == 1) {
                dir = dir + 2;
            } else {
                dir = dir - 2;
            }

            r = r + move_r[dir];
            c = c + move_c[dir];
        }

        // 주사위 업데이트
        dice new_dice;

        if(dir == 0) {
            new_dice.top = 7 - dice_position.right;
            new_dice.right = dice_position.top;
            new_dice.up = dice_position.up;
        } else if(dir == 1) {
            new_dice.top = dice_position.up;
            new_dice.right = dice_position.right;
            new_dice.up = 7 - dice_position.top;
        } else if(dir == 2) {
            new_dice.top = dice_position.right;
            new_dice.right = 7 - dice_position.top;
            new_dice.up = dice_position.up;
        } else if(dir == 3) {
            new_dice.top = 7 - dice_position.up;
            new_dice.right = dice_position.right;
            new_dice.up = dice_position.top;
        }

        dice_position = new_dice;

        // point 획득
        int cnt = search_point(r, c, map[r][c], n, m);
        points += map[r][c] * cnt;

        // 방향 결정
        if(7 - dice_position.top > map[r][c]) {
            // 90도 시계방향
            if(dir == 3) {
                dir = 0;
            } else {
                dir += 1;
            }
        } else if(7 - dice_position.top < map[r][c]) {
            // 90도 반시계방향
            if(dir == 0) {
                dir = 3;
            } else {
                dir -= 1;
            }
        }
    }

    return points;
}


int main() {

    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    map.resize(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    int answer = solution(n, m, k);

    cout << answer;

    return 0;
}