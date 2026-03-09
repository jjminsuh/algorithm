#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t;

    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        int m;

        cin >> n >> m;

        vector<vector<int>> graph(n + 1);

        for(int j = 0; j < m; j++) {
            int start;
            int end;

            cin >> start >> end;

            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        // 최소 신장 트리의 간선 개수는 n-1개이다
        cout << n - 1 << "\n";
    }

    return 0;
}