#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m, 0));
    int check_r[4] = {0, 1, 0, -1};
    int check_c[4] = {1, 0, -1, 0};

    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < m; j++) {
            graph[i][j] = input[j] - '0';
        }
    }

    // 빈 공간에 대해서 갈 수 있는 칸 개수 세기
    // 공간 인덱스 저장
    vector<vector<int>> reachable(n, vector<int>(m, 0));
    int graph_idx = 1;

    map<int, int> reachable_cnt;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 0 && !visited[i][j]) {
                int cnt = 0;

                queue<pair<int, int>> to_visit;
                
                to_visit.push(make_pair(i, j));
                reachable[i][j] = graph_idx;
                visited[i][j] = true;
                cnt++;

                while(!to_visit.empty()) {
                    pair<int, int> front = to_visit.front();
                    to_visit.pop();
                    int r = front.first;
                    int c = front.second;

                    for(int k = 0; k < 4; k++) {
                        if(r + check_r[k] >= 0 && r + check_r[k] < n && c + check_c[k] >= 0 && c + check_c[k] < m) {
                            if(graph[r + check_r[k]][c + check_c[k]] == 0) {
                                if (!visited[r + check_r[k]][c + check_c[k]]) {
                                    to_visit.push(make_pair(r + check_r[k], c + check_c[k]));
                                    reachable[r + check_r[k]][c + check_c[k]] = graph_idx;
                                    visited[r + check_r[k]][c + check_c[k]] = true;
                                    cnt++;
                                }
                            }
                        }
                    }
                }

                reachable_cnt.insert(make_pair(graph_idx, cnt));
                graph_idx += 1;
            }
        }
    }

    // 벽에 대해서 주변 reachable 합산해주기
    vector<vector<int>> answer(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 1) {
                set<int> included_idx;

                for (int k = 0; k < 4; k++) {
                    if (i + check_r[k] >= 0 && i + check_r[k] < n && j + check_c[k] >= 0 && j + check_c[k] < m) {
                        if(graph[i + check_r[k]][j + check_c[k]] == 0) {
                            included_idx.insert(reachable[i + check_r[k]][j + check_c[k]]);
                        }
                    }
                }

                for(auto idx: included_idx) {
                    answer[i][j] += reachable_cnt[idx];
                }

                answer[i][j] += 1;

                cout << answer[i][j] % 10;
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }
    
    return 0;
}