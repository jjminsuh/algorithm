/*
문제 요약

두 개의 나무가 존재
1 2

잡을 수 있는 자두의 최대 개수 구하기
초기 1번에 위치, 최대 W번까지 움직일 수 있음
T초동안 매초 두 나무 중 하나에서 자두가 떨어짐 -> T초후 잡을 수 있는 최대 자두 개수..?

      0 1 2  > 최대 움직일 수 있는 횟수
0(2)
1(1)
2(1)
3(1)
4(2)
5(1)
6(1)
> 매 초를 기록
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  // 입력
  int t = 0;
  int w = 0;

  cin >> t >> w;

  vector<int> fall_tree(t);

  for (int i = 0; i < t; i++)
  {
    cin >> fall_tree[i];
  }

  // memo 배열
  // 행: 시간 0 ~ t - 1, 열: 움직인 횟수 0 ~ w
  // 해당 시간에 움직인 횟수를 활용하며 먹을 수 있는 최대 자두 개수
  vector<vector<int>> memo(t, vector<int>(w + 1, 0));

  // 초기화
  if (fall_tree[0] == 1)
  {
    memo[0][0] = 1;
  }
  else
  {
    memo[0][1] = 1;
  }

  for (int i = 1; i < t; i++)
  {
    for (int j = 0; j <= w; j++)
    {
      // 현재 위치
      int me = 0;

      if (j % 2 == 0)
      {
        me = 1;
      }
      else
      {
        me = 2;
      }

      // 움직이지 않아도 되는 경우
      if (fall_tree[i] == me)
      {
        if (j == 0)
        {
          memo[i][j] = memo[i - 1][j] + 1;
          continue;
        }

        // max(움직이고 안 먹는 경우, 안 움직이고 먹는 경우)
        memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j] + 1);
      }
      else // 움직여야 하는 경우
      {
        if (j == 0)
        {
          memo[i][j] = memo[i - 1][j];
          continue;
        }

        // max(움직이고 먹는 경우, 안 움직이고 안 먹는 경우)
        memo[i][j] = max(memo[i - 1][j - 1] + 1, memo[i - 1][j]);
      }
    }
  }

  // 최대 경우의 수 찾기
  int answer = 0;

  for (int j = 0; j <= w; j++)
  {
    if (answer < memo[t - 1][j])
    {
      answer = memo[t - 1][j];
    }
  }

  cout << answer;

  return 0;
}