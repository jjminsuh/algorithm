#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    int k;

    cin >> n >> k;

    vector<int> temperature(n, 0);
    vector<int> temperature_sum(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> temperature[i];
    }

    // 누적합 구하기
    temperature_sum[0] = temperature[0];

    for(int i = 1; i < n; i++) {
        temperature_sum[i] = temperature_sum[i - 1] + temperature[i];
    }

    // k 구간 sliding하면서 최댓값 찾기
    int answer = temperature_sum[k - 1];

    for(int i = k; i < n; i++) {
        if(answer < temperature_sum[i] - temperature_sum[i - k]) {
            answer = temperature_sum[i] - temperature_sum[i - k];
        }
    }

    cout << answer;

    return 0;
}