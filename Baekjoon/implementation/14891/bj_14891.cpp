#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

vector<deque<int>> wheels;

void rotate(int num, int dir) {
    if(dir == -1) {
        // 반시계 방향
        int teeth = wheels[num - 1].front();
        wheels[num - 1].pop_front();
        wheels[num - 1].push_back(teeth);

    } else if(dir == 1) {
        int teeth = wheels[num - 1].back();
        wheels[num - 1].pop_back();
        wheels[num - 1].push_front(teeth);
    }
}

void move(int num, int dir) {
    // 톱니 극 확인 (같으면 true, 다르면 false)
    // 1, 2번 사이
    bool check1 = (wheels[0][2] == wheels[1][6]);
    // 2, 3번 사이
    bool check2 = (wheels[1][2] == wheels[2][6]);
    // 3, 4번 사이
    bool check3 = (wheels[2][2] == wheels[3][6]);

    // num별로 경우 나눠서 돌리기 진행
    if(num == 1) {
        // 1번 돌리기
        rotate(1, dir);

        if(!check1) {
            // 2번 돌아가야 함
            rotate(2, dir * -1);

            if(!check2) {
                // 3번 돌아가야 함
                rotate(3, dir);

                if(!check3) {
                    // 4번 돌아가야 함
                    rotate(4, dir * -1);
                }
            }
        }
    } else if(num == 2) {
        // 2번 돌리기
        rotate(2, dir);

        if(!check1) {
            // 1번 돌아가야 함
            rotate(1, dir * -1);
        }

        if(!check2) {
            // 3번 돌아가야 함
            rotate(3, dir * -1);

            if(!check3) {
                // 4번 돌아가야 함
                rotate(4, dir);
            }
        }
    } else if(num == 3) {
        // 3번 돌리기
        rotate(3, dir);

        if(!check2) {
            // 2번 돌아가야 함
            rotate(2, dir * -1);

            if(!check1) {
                // 1번 돌아가야 함
                rotate(1, dir);
            }
        }

        if(!check3) {
            // 4번 돌아가야 함
            rotate(4, dir * -1);
        }
    } else if(num == 4) {
        // 4번 돌리기
        rotate(4, dir);

        if (!check3) {
            // 3번 돌아가야 함
            rotate(3, dir * -1);

            if (!check2)
            {
                // 2번 돌아가야 함
                rotate(2, dir);

                if (!check1)
                {
                    // 1번 돌아가야 함
                    rotate(1, dir * -1);
                }
            }
        }
    }

    return;

}

int main() {

    int k = 0;
    
    for(int i = 0; i < 4; i++) {
        deque<int> new_wheel;

        string input;
        cin >> input;

        for(int j = 0; j < 8; j++) {
            new_wheel.push_back(input[j] - '0');
        }

        wheels.push_back(new_wheel);
    }

    cin >> k;

    int score = 0;
    int score_board[4] = {1, 2, 4, 8};

    for(int i = 0; i < k; i++) {
        int num;
        int dir;

        cin >> num >> dir;

        move(num, dir);
    }

    for (int j = 0; j < 4; j++) {
        if (wheels[j].front() == 1) {
            score += score_board[j];
        }
    }

    cout << score;

    return 0;
}