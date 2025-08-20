#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}

vector<int> solution(vector<int> emergency)
{
  vector<int> answer;

  int n = emergency.size();

  vector<pair<int, int>> emergency_with_idx;

  // 인덱스 위치와 값 함께 저장
  for (int i = 0; i < n; i++)
  {
    emergency_with_idx.push_back(make_pair(i, emergency[i]));
  }

  // 응급도 순서대로 정렬
  sort(emergency_with_idx.begin(), emergency_with_idx.end(), compare);

  answer.resize(n);

  // 각 원소의 순위 answer에 지정
  for (int i = 0; i < n; i++)
  {
    answer[emergency_with_idx[i].first] = i + 1;
  }

  return answer;
}