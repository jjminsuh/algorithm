#include <iostream>
#include <vector>

using namespace std;

void diffusion(int r, int c, vector<vector<int>>& map) {
    // 동시에 확산되므로 더해져야하는 값을 따로 관리
    vector<vector<int>> to_add(r, vector<int>(c, 0));
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] == 0) {
                continue;
            }

            // 미세먼지가 있는 경우
            // 확산 될 수 있는 방향 세기
            int dir_cnt = 0;
            int check_r[4] = {-1, 1, 0, 0};
            int check_c[4] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++) {
                if(i + check_r[k] >= 0 && i + check_r[k] < r && j + check_c[k] >= 0 && j + check_c[k] < c) {
                    if(map[i + check_r[k]][j + check_c[k]] != -1) {
                        dir_cnt++;
                        to_add[i + check_r[k]][j + check_c[k]] += map[i][j] / 5;
                    }
                }
            }

            int del_amount = map[i][j] / 5;
            map[i][j] -= del_amount * dir_cnt;
        }
    }

    // 확산된 양 map에 더해주기
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            map[i][j] += to_add[i][j];
        }
    }

    return;
}

void air_purify(int is_top, int purifier_r, int purifier_c, int r, int c, vector<vector<int>>& map) {

    int dir = 0;
    int check_r[2][4] = {{0, -1, 0, 1}, {0, 1, 0, -1}};
    int check_c[2][4] = {{1, 0, -1, 0}, {1, 0, -1, 0}};

    int before_dust = 0;
    bool is_start = true;
    int now_r = purifier_r;
    int now_c = purifier_c;

    while(is_start || !(now_r == purifier_r && now_c == purifier_c)) {
        if (now_r + check_r[is_top][dir] >= 0 && now_r + check_r[is_top][dir] < r && now_c + check_c[is_top][dir] >= 0 && now_c + check_c[is_top][dir] < c)
        {
            is_start = false;

            int save_dust = map[now_r + check_r[is_top][dir]][now_c + check_c[is_top][dir]];

            if(save_dust != -1) {
                map[now_r + check_r[is_top][dir]][now_c + check_c[is_top][dir]] = before_dust;
            }
            
            before_dust = save_dust;

            now_r += check_r[is_top][dir];
            now_c += check_c[is_top][dir];
        }
        else
        {
            if(dir == 4) {
                dir = 0;
            } else {
                dir++;
            }
        }
    }

    return;
}

int main() {

    int r;
    int c;
    int t;

    cin >> r >> c >> t;

    vector<vector<int>> map(r, vector<int>(c, 0));
    pair<int, int> purifier1;
    pair<int, int> purifier2;
    bool has_puri = false;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];

            if(map[i][j] == -1) {
                if(!has_puri) {
                    purifier1 = make_pair(i, j);
                    has_puri = true;
                } else {
                    purifier2 = make_pair(i, j);
                }
            }
        }
    }

    for(int i = 0; i < t; i++) {
        // 미세먼지 확산 진행
        diffusion(r, c, map);

        // 공기청정기 작동
        // 1번 순환
        air_purify(0, purifier1.first, purifier1.second, r, c, map);

        // 2번 순환
        air_purify(1, purifier2.first, purifier2.second, r, c, map);
    }

    int answer = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] != -1) {
                answer += map[i][j];
            }
        }
    }

    cout << answer;

    return 0;
}