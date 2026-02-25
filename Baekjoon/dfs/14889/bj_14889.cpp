#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> ability;
int ability_diff = -1;

int ability_score(set<int> team) {
    int score = 0;

    for(auto i: team) {
        for(auto j: team) {
            if(i == j) {
                continue;
            }

            score += ability[i][j];
        }
    }

    return score;
}


void dfs(int depth, int n, set<int> start_team) {
    if(start_team.size() == n / 2) {
        set<int> link_team;

        for(int i = 1; i <= n; i++) {
            if(start_team.find(i) == start_team.end()) {
                link_team.insert(i);
            }
        }

        int start_score = ability_score(start_team);
        int link_score = ability_score(link_team);

        if(ability_diff == -1) {
            ability_diff = abs(start_score - link_score);
        } else {
            if(ability_diff > abs(start_score - link_score)) {
                ability_diff = abs(start_score - link_score);
            }
        }

        return;
    }

    if(depth == n) {
        return;
    }

    start_team.insert(depth + 1);
    dfs(depth + 1, n, start_team);
    start_team.erase(depth + 1);
    dfs(depth + 1, n, start_team);
}


int main() {

    int n = 0;

    cin >> n;

    ability.resize(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> ability[i][j];
        }
    }

    set<int> start_team;

    dfs(0, n, start_team);

    cout << ability_diff;


    return 0;
}