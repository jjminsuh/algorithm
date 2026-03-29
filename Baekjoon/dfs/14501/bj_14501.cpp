#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int day, int n, vector<pair<int, int>> &plans, int before, int money) {
    if(day <= n) {
        // 해당 상담 받을 수 있는 경우에만 money 나중에 저장
        money += plans[before].second;
    }

    // 더 이상 상담 받을 수 없는 경우 > 퇴사일에 도달 (day가 오늘 일수)
    if(day >= n) {
        if(answer < money) {
            answer = money;
        }

        return;
    }

    // 모든 경우 탐색
    for(int i = day + 1; i <= n; i++) {
        dfs(i + plans[i].first - 1, n, plans, i, money);
    }
}


int main() {

    int n;

    cin >> n;

    vector<pair<int, int>> plans;

    // dummy 데이터 추가 (인덱스 1부터 시작하도록)
    plans.push_back(make_pair(0, 0));

    for(int i = 0; i < n; i++) {
        int t;
        int p;

        cin >> t >> p;

        plans.push_back(make_pair(t, p));
    }

    // 모든 경우를 탐색
    for(int i = 1; i <= n; i++) {
        dfs(i + plans[i].first - 1, n, plans, i, 0);
    }

    cout << answer;

    return 0;
}