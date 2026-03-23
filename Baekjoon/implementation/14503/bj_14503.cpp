#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    int m;

    cin >> n >> m;

    int r;
    int c;
    int dir;

    cin >> r >> c >> dir;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;

    int check_r[4] = {-1, 0, 1, 0};
    int check_c[4] = {0, 1, 0, -1};

    while(answer <= n * m) {

        if(map[r][c] == 0) {
            map[r][c] = 2;
            answer++;
        }

        // 주변 4칸 확인
        bool has_moved = false;

        // 반시계 방향 순서대로 확인
        for(int k = 3; k >= 0; k--) {
            int new_dir = (dir + k) % 4;

            if (r + check_r[new_dir] >= 0 && r + check_r[new_dir] < n && c + check_c[new_dir] >= 0 && c + check_c[new_dir] < m) {
                if (map[r + check_r[new_dir]][c + check_c[new_dir]] == 0) {
                    has_moved = true;
                    r = r + check_r[new_dir];
                    c = c + check_c[new_dir];
                    dir = new_dir;

                    break;
                }
            }
        }

        // 4칸 중 청소되지 않은 빈칸 없는 경우
        if(!has_moved) {
            // 후진 가능한지 확인
            int back_dir = -1;

            if(dir == 0 || dir == 1) {
                back_dir = dir + 2;
            } else {
                back_dir = dir - 2;
            }

            if (r + check_r[back_dir] >= 0 && r + check_r[back_dir] < n && c + check_c[back_dir] >= 0 && c + check_c[back_dir] < m) {
                if (map[r + check_r[back_dir]][c + check_c[back_dir]] != 1) {
                    r = r + check_r[back_dir];
                    c = c + check_c[back_dir];
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    cout << answer;

    return 0;
}