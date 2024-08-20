#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n = 0;
    vector <int> memo;

    scanf("%d", &n);

    memo.push_back(0);

    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            memo.push_back(1);
            continue;
        }

        if(i == 2) {
            memo.push_back(2 + memo[i - 1]);
            continue;
        }

        memo.push_back(((memo[i - 2] * 2) + memo[i - 1]) % 10007);
    }

    printf("%d", memo[n]);


    return 0;
}