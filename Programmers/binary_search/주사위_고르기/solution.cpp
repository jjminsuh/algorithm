#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int FACE = 6;

int half_size;
int max_win_cnt = 0;
vector<int> max_dice;
vector<vector<int>> dice_info;

// 주사위 여러개 주어졌을 때 만들 수 있는 숫자 합
void get_points(int depth,
                vector<int> &points,
                vector<int> selected,
                int point)
{

  if (depth == selected.size())
  {
    points.push_back(point);
    return;
  }

  for (int i = 0; i < FACE; i++)
  {
    get_points(depth + 1, points, selected, point + dice_info[selected[depth]][i]);
  }
}

// 해당 dice 조합에서 이기는 경우의 수 세기
// 6^5 * log 6^5
int get_win_cnt(vector<int> &a_dice, vector<int> &b_dice)
{
  // a가 고른 주사위로 만들 수 있는 모든 수
  vector<int> a_points;
  get_points(0, a_points, a_dice, 0);

  // b가 고른 주사위로 만들 수 있는 모든 수
  vector<int> b_points;
  get_points(0, b_points, b_dice, 0);

  // b가 고른 주사위로 만든 수들 오름차순 정렬
  sort(b_points.begin(), b_points.end());

  // a points에 대해서 이진탐색으로 승수 계산
  int cnt = 0;

  for (int i = 0; i < a_points.size(); i++)
  {
    int start = 0;
    int end = b_points.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
      if (a_points[i] > b_points[mid])
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }

      mid = (start + end) / 2;
    }

    cnt += (start - 1) + 1;
  }

  return cnt;
}

// 모든 dice를 고르는 경우의 찾는 dfs 함수
void get_dice(int depth, set<int> a_dice, int before)
{
  if (depth == half_size)
  {
    // 이기는 경우의 수 계산
    // b_dice 찾기
    vector<int> b_dice_arr;
    vector<int> a_dice_arr;
    for (int i = 0; i < dice_info.size(); i++)
    {
      if (a_dice.find(i) == a_dice.end())
      {
        b_dice_arr.push_back(i);
      }
      else
      {
        a_dice_arr.push_back(i);
      }
    }

    int win_cnt = get_win_cnt(a_dice_arr, b_dice_arr);

    // 최댓값 갱신
    if (win_cnt > max_win_cnt)
    {
      max_win_cnt = win_cnt;
      max_dice = a_dice_arr;
    }
  }

  for (int i = before + 1; i < dice_info.size(); i++)
  {
    a_dice.insert(i);
    get_dice(depth + 1, a_dice, i);
    a_dice.erase(i);
  }
}

vector<int> solution(vector<vector<int>> dice)
{
  vector<int> answer;

  dice_info = dice;

  // dice.size() <= 10 이므로 완전탐색해도 괜찮을 듯...!
  // A가 가져가야하는 주사위 개수
  half_size = dice.size() / 2;

  // A의 dice -> 처음에는 빈 set
  set<int> a_dice;

  get_dice(0, a_dice, -1);

  for (int i = 0; i < max_dice.size(); i++)
  {
    answer.push_back(max_dice[i] + 1);
  }

  return answer;
}