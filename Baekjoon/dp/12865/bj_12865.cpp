#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    int n;
    int k;
    vector<pair<int, int>> things;
    
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int weight;
        int value;
        cin >> weight >> value;

        things.push_back(make_pair(weight, value));
    }

    // memo[i][j]: i번째 물건까지 고려했을 때, 무게가 j인 것 중 최고 가치
    vector<vector<int>> memo(n + 1, vector<int>(k + 1));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            // 새 물건보다 더 적은 목표 무게 인 경우
            if(j < things[i - 1].first) {
                memo[i][j] = memo[i - 1][j];
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - things[i - 1].first] + things[i - 1].second);
            }
        }
    }

    int answer = 0;

    for(int j = 0; j <= k; j++) {
        if(answer < memo[n][j]) {
            answer = memo[n][j];
        }
    }

    cout << answer;

    return 0;
}