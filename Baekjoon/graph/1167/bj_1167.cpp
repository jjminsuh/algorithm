#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int idx = 0;

void dfs(int now_v, vector<bool> &visited, vector<vector<pair<int, int>>> &tree, int sum) {
    for(int i = 0; i < tree[now_v].size(); i++) {
        if(visited[tree[now_v][i].first]) {
            continue;
        }

        visited[tree[now_v][i].first] = true;

        if(sum + tree[now_v][i].second > answer) {
            answer = sum + tree[now_v][i].second;
            idx = tree[now_v][i].first;
        }

        dfs(tree[now_v][i].first, visited, tree, sum + tree[now_v][i].second);
    }

    return;
}

int main() {

    int v;
    
    cin >> v;

    // (end, length) 쌍 저장
    vector<vector<pair<int, int>>> tree(v + 1);

    for(int i = 0; i < v; i++) {
        int start;

        cin >> start;

        while(true) {
            int end;

            cin >> end;

            if(end == -1) {
                break;
            }

            int l;

            cin >> l;

            tree[start].push_back(make_pair(end, l));
        }
    }

    vector<bool> visited(v + 1, false);
    
    // 임의의 노드에서 가장 먼 노드 찾기
    visited[1] = true;
    dfs(1, visited, tree, 0);

    // 찾은 가장 먼 노드에서 가장 먼 노드 찾기
    visited = vector<bool>(v + 1, false);
    answer = 0;
    visited[idx] = true;
    dfs(idx, visited, tree, 0);

    cout << answer;

    return 0;
}