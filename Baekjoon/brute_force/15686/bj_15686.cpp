#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int answer = 0;

int cal_chicken_length(int n, int m, vector<vector<int>> &graph, set<pair<int, int>> &take_chicken, vector<pair<int, int>> houses) {
    int sum = 0;

    // 집들에 대해서 치킨거리 계산
    for(int i = 0; i < houses.size(); i++) {
        int r = houses[i].first;
        int c = houses[i].second;

        int min = 2 * n;

        for(auto chicken: take_chicken) {
            int length = abs(r - chicken.first) + abs(c - chicken.second);

            if(min > length) {
                min = length;
            }
        }

        sum += min;
    }

    return sum;
}

void choose_chicken(int n, int m, vector<vector<int>> &graph, set<pair<int, int>> take_chicken, vector<pair<int, int>> &chickens, int before, vector<pair<int, int>> &houses) {
    if(take_chicken.size() >= m) {
        if(take_chicken.size() == m) {
            // 치킨거리 계산
            int length = cal_chicken_length(n, m, graph, take_chicken, houses);

            if(length < answer) {
                answer = length;
            }

            return;
        }

        return;
    }

    for(int i = before + 1; i < chickens.size(); i++) {
        take_chicken.insert(chickens[i]);
        choose_chicken(n, m, graph, take_chicken, chickens, i, houses);
        take_chicken.erase(chickens[i]);
    }
}


int main() {

    int n;
    int m;
    
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<pair<int, int>> chickens;
    vector<pair<int, int>> houses;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 2) {
                chickens.push_back(make_pair(i, j));
            }

            if(graph[i][j] == 1) {
                houses.push_back(make_pair(i, j));
            }
        }
    }

    answer = 2 * n * 2 * n;

    set<pair<int, int>> take_chicken;

    choose_chicken(n, m, graph, take_chicken, chickens, -1, houses);

    cout << answer;

    return 0;
}