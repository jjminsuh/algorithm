#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
  vector<int> answer(4, 0);

  set<int> nodes;
  // vector<vector<int> > node_edges_out;
  // vector<vector<int> > node_edges_in;
  vector<int> node_edges_out;
  vector<int> node_edges_in;

  // 개별 총 노드 찾아서 저장
  for (int i = 0; i < edges.size(); i++)
  {
    nodes.insert(edges[i][0]);
    nodes.insert(edges[i][1]);
  }

  // 노드 -> 노드 간선 정보 다시 저장 (나가는 방향, 들어오는 방향)
  // node_edges_out.resize(nodes.size() + 1);
  // node_edges_in.resize(nodes.size() + 1);
  node_edges_out.resize(nodes.size() + 1, 0);
  node_edges_in.resize(nodes.size() + 1, 0);

  for (int i = 0; i < edges.size(); i++)
  {
    // node_edges_out[edges[i][0]].push_back(edges[i][1]);
    // node_edges_in[edges[i][1]].push_back(edges[i][0]);
    node_edges_out[edges[i][0]]++;
    node_edges_in[edges[i][1]]++;
  }

  // 새로운 정점 찾기 -> 들어오는 edge가 없는 노드 + 나가는 간선이 2개 이상
  int new_node = -1;

  for (int i = 1; i <= node_edges_in.size(); i++)
  {
    if (node_edges_in[i] == 0 && node_edges_out[i] >= 2)
    {
      new_node = i;
    }
  }

  answer[0] = new_node;
  int total = node_edges_out[new_node];

  // 막대, 8자 그래프 개수 세기
  for (auto node : nodes)
  {
    // 막대그래프의 마지막 노드를 찾으면 막대++
    if (node_edges_out[node] == 0)
    {
      answer[2]++;
      continue;
    }

    // 8자 그래프의 가운데 노드를 찾으면 8자++
    if (node_edges_in[node] >= 2 && node_edges_out[node] == 2)
    {
      answer[3]++;
      continue;
    }
  }

  answer[1] = total - answer[2] - answer[3];

  return answer;
}