#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {

    int n;
    int m;
    int idx = 1;

    cin >> n >> m;

    while(!(n == 0 && m == 0)) {
        vector<vector<int>> graph(n + 1);

        for (int i = 0; i < m; i++)
        {
            int start = 0;
            int end = 0;
            cin >> start >> end;

            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        int cnt = 0;

        // 이미 사용한 노드 저장
        set<int> used_nodes;

        // 모든 노드가 root 후보가 될 수 있음
        for(int i = 1; i <= n; i++) {
            // 이미 다른 완성된 tree에 있는 노드는 건너뜀
            if (used_nodes.find(i) != used_nodes.end()) {
                continue;
            }

            vector<int> visited(n + 1);
            map<int, int> parents;
            queue<int> to_visit;
            set<int> tree_nodes;

            // 현재 위치 저장 - bfs로 탐색 진행
            to_visit.push(i);
            visited[i] = true;
            parents.insert(make_pair(i, -1));
            tree_nodes.insert(i);

            bool is_tree = true;

            while(!to_visit.empty()) {
                int front = to_visit.front();
                to_visit.pop();

                for(int j = 0; j < graph[front].size(); j++) {
                    // 이미 방문했다면 부모가 둘 이상 -> 트리가 아님
                    if(visited[graph[front][j]]) {
                        // 단 양방향 간선이므로 이미 저장되어있던 내 부모가 나타난 경우는 넘어간다.
                        if(graph[front][j] == parents[front]) {
                            continue;
                        }

                        is_tree = false;
                        break;
                    } else {
                        to_visit.push(graph[front][j]);
                        visited[graph[front][j]] = true;
                        parents.insert(make_pair(graph[front][j], front));
                        tree_nodes.insert(graph[front][j]);
                    }
                }

                if (!is_tree) {
                    break;
                }
            }

            // 해당 root로 완성할 수 있는 트리가 존재 -> 노드들 저장 및 count 증가
            if(is_tree) {
                used_nodes.insert(tree_nodes.begin(), tree_nodes.end());
                cnt++;
            }
        }

        cout << "Case " << idx << ": ";

        if(cnt == 0) {
            cout << "No trees.\n";
        } else if(cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << cnt << " trees.\n";
        }

        idx++;

        cin >> n >> m;
    }

    return 0;
}