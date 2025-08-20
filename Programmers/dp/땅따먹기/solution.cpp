#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
  int answer = 0;

  int n = land.size();
  // 각 칸에 도달할 수 있는 최댓값 계산
  vector<vector<int>> memo(n, vector<int>(4, 0));

  for (int i = 0; i < n; i++)
  {
    // 첫 행 초기화
    if (i == 0)
    {
      for (int j = 0; j < 4; j++)
      {
        memo[i][j] = land[i][j];
      }

      continue;
    }

    // 4개 열 모두 대입해보며 최댓값 찾기
    for (int j = 0; j < 4; j++)
    {
      int max = 0;

      for (int k = 0; k < 4; k++)
      {
        if (k == j)
        { // 같은 열은 밟을 수 없다
          continue;
        }

        if (max < memo[i - 1][k])
        {
          max = memo[i - 1][k];
        }
      }

      // 다음 행의 각 칸에 도달할 때 최대 점수 저장
      memo[i][j] = land[i][j] + max;
    }
  }

  // 마지막 행에서 최고점 찾기
  for (int i = 0; i < 4; i++)
  {
    if (answer < memo[n - 1][i])
    {
      answer = memo[n - 1][i];
    }
  }

  return answer;
}