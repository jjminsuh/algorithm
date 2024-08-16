#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n = 0;

    scanf("%d", &n);

    vector <int> memo;

    memo.push_back(0);

    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            memo.push_back(1);
            continue;
        }

        if(i == 2) {
            memo.push_back(memo[i - 1] + 1);
            continue;
        }

        memo.push_back((memo[i - 1] + memo[i - 2]) % 10007);
    }

    printf("%d", memo[n]);

    return 0;
}
