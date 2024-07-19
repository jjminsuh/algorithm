#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

    int M = 0;
    int N = 0;

    vector< vector<char> > board;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        
        vector<char> rowTmp;

        for(int j = 0; j < M; j++) {
            char tmp = ' ';
            scanf(" %c", &tmp);
            rowTmp.push_back(tmp);
        }

        board.push_back(rowTmp);
    }

    int min = 64;

    for(int i = 0; i < (N - 7); i++) {
        for(int j = 0; j < (M - 7); j++) {
            char before = board[i][j];
            int cnt = 0;
            
            for(int nIter = 0; nIter < 8; nIter++) {
                for(int mIter = 0; mIter < 8; mIter++) {
                    if(nIter == 0 && mIter == 0) {
                        continue;
                    }

                    if(before == board[i + nIter][j + mIter]) {
                        cnt++;

                        if(board[i + nIter][j + mIter] == 'W') {
                            before = 'B';
                        } else {
                            before = 'W';
                        }
                    } else {
                        before = board[i + nIter][j + mIter];
                    }
                }

                if(before == 'W') {
                    before = 'B';
                } else {
                    before = 'W';
                }
            }

            if(cnt < min) {
                min = cnt;
            }

            // 반대인 경우
            cnt = 0;

            if(board[i][j] == 'W') {
                before = 'B';
            } else {
                before = 'W';
            }

            cnt++;

            for(int nIter = 0; nIter < 8; nIter++) {
                for(int mIter = 0; mIter < 8; mIter++) {
                    if(nIter == 0 && mIter == 0) {
                        continue;
                    }

                    if(before == board[i + nIter][j + mIter]) {
                        cnt++;
                        if(board[i + nIter][j + mIter] == 'W') {
                            before = 'B';
                        } else {
                            before = 'W';
                        }
                    } else {
                        before = board[i + nIter][j + mIter];
                    }
                }

                if(before == 'W') {
                    before = 'B';
                } else {
                    before = 'W';
                }
            }

            if(cnt < min) {
                min = cnt;
            }
        }
    }

    printf("%d", min);

    return 0;
}