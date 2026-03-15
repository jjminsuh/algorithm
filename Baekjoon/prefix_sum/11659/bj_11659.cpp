#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    int m = 0;

    cin >> n >> m;

    vector<int> cum_sum(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        cum_sum[i] = cum_sum[i - 1] + num;
    }

    for(int i = 0; i < m; i++) {
        int start = 0;
        int end = 0;

        cin >> start >> end;

        cout << cum_sum[end] - cum_sum[start - 1] << "\n";
    }

    return 0;
}