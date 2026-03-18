#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dir_r[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dir_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<int>> water_map;
set<pair<int, int>> clouds;
set<pair<int, int>> moved_clouds;

pair<int, int> move_cloud(int r, int c, int dir, int s, int n) {
    int new_r = (r + (s * dir_r[dir - 1])) % n ;
    int new_c = (c + (s * dir_c[dir - 1])) % n;

    if(new_r < 0) {
        new_r = n + new_r;
    } else if(new_r >= n) {
        new_r = new_r - n;
    }

    if(new_c < 0) {
        new_c = n + new_c % n;
    } else if(new_c >= n) {
        new_c = new_c - n;
    }

    return make_pair(new_r, new_c);
}

void solution(int dir, int s, int n) {
    // 각 구름 이동
    for(auto cloud: clouds) {
        pair<int, int> moved_place = move_cloud(cloud.first, cloud.second, dir, s, n);

        moved_clouds.insert(moved_place);
    }

    // 구름 칸의 물 증가
    for(auto cloud: moved_clouds) {
        water_map[cloud.first][cloud.second]++;
    }

    // 물 복사 버그 진행
    for(auto cloud: moved_clouds) {
        int cnt = 0;

        for (int k = 1; k < 8; k += 2) {
            if (cloud.first + dir_r[k] >= 0 && cloud.first + dir_r[k] < n && cloud.second + dir_c[k] >= 0 && cloud.second + dir_c[k] < n) {
                if (water_map[cloud.first + dir_r[k]][cloud.second + dir_c[k]] > 0) {
                    cnt++;
                }
            }
        }

        water_map[cloud.first][cloud.second] += cnt;
    }

    //새로운 구름 생성
    clouds.clear();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(water_map[i][j] >= 2) {
                if(moved_clouds.find(make_pair(i, j)) == moved_clouds.end()) {
                    water_map[i][j] -= 2;
                    clouds.insert(make_pair(i, j));
                }
            }
        }
    }

    moved_clouds.clear();

    return;
}

int main() {

    int n;
    int m;

    cin >> n >> m;

    water_map.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> water_map[i][j];
        }
    }

    // 초기 구름 추가
    clouds.insert(make_pair(n - 1, 0));
    clouds.insert(make_pair(n - 1, 1));
    clouds.insert(make_pair(n - 2, 0));
    clouds.insert(make_pair(n - 2, 1));

    for(int i = 0; i < m; i++) {
        int dir = 0;
        int s = 0;

        cin >> dir >> s;

        solution(dir, s, n);
    }

    

    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            answer += water_map[i][j];
        }
    }

    cout << answer;

    return 0;
}