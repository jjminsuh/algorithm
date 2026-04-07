#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int m;
    int n;
    int h;

    cin >> m >> n >> h;

    vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m, -1)));
    int total_tomato = 0;
    queue<pair<int, pair<int, int>>> new_start_points;
    queue<pair<int, pair<int, int>>> start_points;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> tomato[i][j][k];

                if(tomato[i][j][k] != -1) {
                    total_tomato++;
                }

                if(tomato[i][j][k] == 1) {
                    new_start_points.push(make_pair(i, make_pair(j, k)));
                }
            }
        }
    }

    
    int answer = 0;

    if (new_start_points.size() == total_tomato)
    {
        cout << answer;

        return 0;
    }

    int check_h[6] = {0, 0, 0, 0, 1, -1};
    int check_r[6] = {1, -1, 0, 0, 0, 0};
    int check_c[6] = {0, 0, 1, -1, 0, 0};

    while(!new_start_points.empty()) {
        // 일마다 starting point 갱신
        start_points = new_start_points;
        new_start_points = queue<pair<int, pair<int, int>>>();
        
        // 바로 주변만 확인
        while(!start_points.empty()) {
            pair<int, pair<int, int>> front = start_points.front();
            start_points.pop();

            int now_h = front.first;
            int now_r = front.second.first;
            int now_c = front.second.second;

            // 6방향으로 퍼져나가기
            for(int i = 0; i < 6; i++) {
                if(now_h + check_h[i] >= 0 && now_h + check_h[i] < h && now_r + check_r[i] >= 0 && now_r + check_r[i] < n && now_c + check_c[i] >= 0 && now_c + check_c[i] < m) {
                    if (tomato[now_h + check_h[i]][now_r + check_r[i]][now_c + check_c[i]] == 0) {
                            tomato[now_h + check_h[i]][now_r + check_r[i]][now_c + check_c[i]] = 1;
                            // 다음날 퍼져나갈 수 있는 source가 됨
                            new_start_points.push(make_pair(now_h + check_h[i], make_pair(now_r + check_r[i], now_c + check_c[i])));
                    }
                }
            }
        }
        
        answer++;
    }

    // 모든 토마토 익었는지 확인
    int good_tomato = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(tomato[i][j][k] == 1) {
                    good_tomato++;
                }
            }
        }
    }

    if(good_tomato == total_tomato) {
        cout << answer - 1;
    } else {
        cout << -1;
    }

    return 0;
}