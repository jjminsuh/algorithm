#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(int x, int y) {
        return x > y;
    }
};

int main() {

    int t = 0;

    cin >> t;

    for(int i = 0; i < t; i++) {
        int m = 0;
        cin >> m;

        priority_queue<int> small;
        priority_queue<int, vector<int>, compare> big;
        int cnt = 0;

        vector<int> answer;

        for(int j = 1; j <= m; j++) {
            int input;
            cin >> input;

            if (big.empty()) {
                // 가장 처음에는 big에 넣기
                big.push(input);
            } else {
                // small과 big의 크기를 유지시키면서 big의 top이 중앙값이 유지되도록 삽입
                int big_top = big.top();

                if (big_top >= input)
                {   
                    if(!small.empty()) {
                        int small_top = small.top();

                        if(small_top >= input) {
                            if(small.size() == big.size()) {
                                small.pop();
                                big.push(small_top);
                                small.push(input);
                            } else {
                                small.push(input);
                            }
                        } else {
                            if(big.size() - small.size() == 1) {
                                // big.pop();
                                // small.push(big_top);
                                // big.push(input);
                                small.push(input);
                            } else {
                                big.push(input);
                            }
                        }
                    } else {
                        small.push(input);
                    }
                }
                else {
                    if (!small.empty()) {
                        int small_top = small.top();

                        if (small_top < input) {
                            if(big.size() - small.size() == 1) {
                                big.pop();
                                small.push(big_top);
                                big.push(input);
                            } else {
                                big.push(input);
                            }
                        }
                        else {
                            if (big.size() == small.size()) {
                                small.pop();
                                big.push(small_top);
                                small.push(input);
                            }
                            else {
                                small.push(input);
                            }
                        }
                    }
                    else {
                        big.pop();
                        small.push(big_top);
                        big.push(input);
                    }
                }
            }

            if(j % 2 == 1) {
                answer.push_back(big.top());
            }
        }

        cout << answer.size() << "\n";

        for(int j = 1; j <= answer.size(); j++) {
            cout << answer[j - 1];

            if(j % 10 == 0) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }

        if(answer.size() % 10 != 0) {
            cout << "\n";
        }
    }

    return 0;
}