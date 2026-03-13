#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int v;
    int e;

    cin >> v >> e;

    vector<vector<pair<int, int>>> graph(v + 1);

    int start_node;

    cin >> start_node;

    for(int i = 0; i < e; i++) {
        int start_edge;
        int end_edge;
        int weight;

        cin >> start_edge >> end_edge >> weight;

        graph[start_edge].push_back(make_pair(end_edge, weight));
    }

    vector<int> answer(v + 1, -1);
    priority_queue<pair<int, int>> to_visit;

    to_visit.push(make_pair(0, start_node));
    answer[start_node] = 0;

    while(!to_visit.empty()) {
        pair<int, int> front = to_visit.top();
        to_visit.pop();

        for(int i = 0; i < graph[front.second].size(); i++) {
            int next_node = graph[front.second][i].first;
            int weight = graph[front.second][i].second;
            
            if(answer[next_node] == -1 || answer[next_node] > answer[front.second] + weight) {
                answer[next_node] = answer[front.second] + weight;
                to_visit.push(make_pair(-1 * answer[next_node], next_node));
            } 
        }
    }

    for(int i = 1; i <= v; i++) {
        if(answer[i] == -1) {
            cout << "INF\n";
        } else {
            cout << answer[i] << "\n";
        }
    }

    return 0;
}