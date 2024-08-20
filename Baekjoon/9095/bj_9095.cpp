#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t = 0;

    scanf("%d", &t);

    vector <int> memo;

    memo.push_back(0);

    for(int j = 0; j < t; j++) {
        
        int n = 0;

        scanf(" %d", &n);

        if(memo.size() > n) {
            printf("%d\n", memo[n]);
            continue;
        }

        for(int i = memo.size(); i <= n; i++) {
            if(i == 1) {
                memo.push_back(1);
                continue;
            }

            if(i == 2) {
                memo.push_back(memo[i - 1] + 1);
                continue;
            }

            if(i == 3) {
                memo.push_back(memo[i - 2] + memo[i - 1] + 1);
                continue;
            }

            memo.push_back(memo[i - 3] + memo[i - 2] + memo[i - 1]);
        }

        printf("%d\n", memo[n]);
    }

    return 0;
}