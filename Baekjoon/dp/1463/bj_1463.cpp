#include <iostream>

using namespace std;

int main() {

    int n = 0;
    int minCnt = 0;
    int cnt = 0;

    scanf("%d", &n);

    int memo[1000001] = {0,};

    for(int i = 1; i <= n; i++) {
        minCnt = i;
        cnt = 0;

        if(i == 1) {
            memo[i] = 0;
            continue;
        }

        if(i % 3 == 0) {
            cnt = 0;
            cnt = memo[i/3] + 1;
            
            if(cnt < minCnt) {
                minCnt = cnt;
            }
        }

        if(i % 2 == 0) {
            cnt = 0;
            cnt = memo[i/2] + 1;
            
            if(cnt < minCnt) {
                minCnt = cnt;
            }
        }

        cnt = 0;
        cnt = memo[i - 1] + 1;

        if(cnt < minCnt) {
            minCnt = cnt;
        }

        memo[i] = minCnt;
    }

    printf("%d", memo[n]);

    return 0;
}