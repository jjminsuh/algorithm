#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    int l;

    cin >> n >> l;

    vector<vector<int>> map(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;

    // 가로 길의 개수 세기
    for(int i = 0; i < n; i++) {
        bool can_go = true;

        int col = 0;
        int now_height = map[i][col];

        vector<bool> has_road(n, false);

        while(col < n) {
            if(col + 1 == n) {
                break;
            }

            // 다음칸의 높이가 같으면 진행
            if(map[i][col + 1] == now_height) {
                col++;
                continue;
            }

            // 다음칸의 높이가 다른 경우
            if(abs(now_height - map[i][col + 1]) > 1) {
                // 높이 차이가 1보다 크면 진행 불가
                can_go = false;
                break;
            } else {
                // 높이 차이가 1인 경우 낮은 쪽 높이가 l개 연속으로 있어야 함
                // 내려가는 경우
                if(now_height > map[i][col + 1]) {
                    bool put_road = true;
                    int new_height = map[i][col + 1];

                    // 앞으로 l개 연속으로 존재하는지 확인
                    for (int k = 1; k <= l; k++) {
                        if (col + k >= n || map[i][col + k] != new_height) {
                            put_road = false;
                            break;
                        }
                    }

                    if (!put_road) {
                        can_go = false;
                        break;
                    } else {
                        // 경사로 놓은 부분 표시
                        for(int k = 1; k <= l; k++) {
                            has_road[col + k] = true;
                        }

                        col = col + l;
                        now_height = map[i][col];
                    }
                } else {
                    // 더 높이 올라가야하는 경우
                    bool put_road = true;
                    int new_height = map[i][col + 1];

                    // 나 포함 뒤쪽으로 l개 존재하는지 확인
                    for(int k = 0; k < l; k++) {
                        // 경사로 이미 놓였는지도 확인
                        if(col - k < 0 || map[i][col - k] != now_height || has_road[col - k]) {
                            put_road = false;
                            break;
                        }
                    }

                    if(!put_road) {
                        can_go = false;
                        break;
                    } else {
                        now_height = new_height;
                        col++;
                    }
                }
                
            }
        }

        if(can_go) {
            answer++;
        }
    }

    // 세로 길의 개수 세기
    for (int j = 0; j < n; j++) {
        bool can_go = true;

        int row = 0;
        int now_height = map[row][j];

        vector<bool> has_road(n, false);

        while (row < n) {
            if (row + 1 == n) {
                break;
            }

            // 다음칸의 높이가 같으면 진행
            if (map[row + 1][j] == now_height) {
                row++;
                continue;
            }

            // 다음칸의 높이가 다른 경우
            if (abs(now_height - map[row + 1][j]) > 1) {
                // 높이 차이가 1보다 크면 진행 불가
                can_go = false;
                break;
            } else {
                // 높이 차이가 1인 경우 낮은 쪽 높이가 l개 연속으로 있어야 함
                // 내려가는 경우
                if (now_height > map[row + 1][j]) {
                    bool put_road = true;
                    int new_height = map[row + 1][j];

                    // l개 연속으로 있는지 확인
                    for (int k = 1; k <= l; k++) {
                        if (row + k >= n || map[row + k][j] != new_height) {
                            put_road = false;
                            break;
                        }
                    }

                    if (!put_road) {
                        can_go = false;
                        break;
                    } else {
                        // 경사로 놓은 위치 표시
                        for (int k = 1; k <= l; k++) {
                            has_road[row + k] = true;
                        }

                        row = row + l;
                        now_height = map[row][j];
                    }
                } else {
                    // 올라가는 경우
                    bool put_road = true;
                    int new_height = map[row + 1][j];

                    // 나 포함 뒤로 l개 있는지 확인
                    for (int k = 0; k < l; k++) {
                        // 경사로 이미 놓였는지도 확인해야 함
                        if (row - k < 0 || map[row - k][j] != now_height || has_road[row - k]) {
                            put_road = false;
                            break;
                        }
                    }

                    if (!put_road) {
                        can_go = false;
                        break;
                    } else {
                        now_height = new_height;
                        row++;
                    }
                }
            }
        }

        if (can_go) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}