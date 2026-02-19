#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
int check_r[4] = {0, 1, 0, -1};
int check_c[4] = {1, 0, -1, 0};
int max_block = 0;

int exp(int n) {
    int res = 1;

    for(int i = 0; i < n; i++) {
        res *= 2;
    }

    return res;
}

void rotate(int r, int c, int size)
{
    vector<vector<int>> tmp_map(size, vector<int>(size));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tmp_map[i][j] = map[r + i][c + j];
        }
    }

    // 90도 돌려서 map에 다시 넣기
    for (int j = size - 1; j >= 0; j--)
    {
        for (int i = 0; i < size; i++)
        {
            map[r + i][c + j] = tmp_map[size - 1 - j][i];
        }
    }
}

void do_magic(int block_size) {

    int size = exp(block_size);

    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map.size(); j++) {
            if(i % size == 0 && j % size == 0) {
                rotate(i, j, size);
            }
        }
    }
}

void reduce_ice() {
    vector<pair<int, int>> to_reduce;

    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map.size(); j++) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                if(i + check_r[k] >= 0 && i + check_r[k] < map.size() && j + check_c[k] >= 0 && j + check_c[k] < map.size()) {
                    if(map[i + check_r[k]][j + check_c[k]] > 0) {
                        cnt++;
                    }
                }
            }

            if(cnt < 3) {
                to_reduce.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < to_reduce.size(); i++) {
        if (map[to_reduce[i].first][to_reduce[i].second] >= 1) {
            map[to_reduce[i].first][to_reduce[i].second]--;
        }
    }

    return;
}

void search_block() {

    vector<vector<bool>> visited(map.size(), vector<bool>(map.size()));

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map.size(); j++) {
            if(visited[i][j] || map[i][j] <= 0) {
                continue;
            }

            int cnt = 0;
            queue<pair<int, int>> to_visit; 
            to_visit.push(make_pair(i, j));
            visited[i][j] = true;
            cnt++;

            while(!to_visit.empty()) {
                pair<int, int> front = to_visit.front();
                to_visit.pop();

                for (int k = 0; k < 4; k++) {
                    if (front.first + check_r[k] >= 0 && front.first + check_r[k] < map.size() && front.second + check_c[k] >= 0 && front.second + check_c[k] < map.size()) {
                        if(!visited[front.first + check_r[k]][front.second + check_c[k]]) {
                            visited[front.first + check_r[k]][front.second + check_c[k]] = true;
                            if (map[front.first + check_r[k]][front.second + check_c[k]] > 0) {
                                cnt++;
                                to_visit.push(make_pair(front.first + check_r[k], front.second + check_c[k]));
                            }
                        }
                    }
                }
            }

            if(cnt > max_block) {
                max_block = cnt;
            }
        }
    }
}

int main() {

    int n = 0;
    int q = 0;

    cin >> n >> q;

    int exp_n = exp(n);

    map.resize(exp_n, vector<int>(exp_n));

    for(int i = 0; i < exp_n; i++) {
        for(int j = 0; j < exp_n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        int block_size;
        cin >> block_size;

        // 마법사 상어가 기술 시전
        do_magic(block_size);

        // 탐색하며 3개 이상 얼음이 인접하지 않은 칸의 얼음 양 줄이기
        reduce_ice();
    }

    int sum_ice = 0;

    for(int i = 0; i < exp_n; i++) {
        for(int j = 0; j < exp_n; j++) {
            if(sum_ice >= 0) {
                sum_ice += map[i][j];
            }
        }
    }

    search_block();

    cout << sum_ice << "\n" << max_block;

    return 0;
}