#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct RotateInfo
{
  int angle;
  int r;
  int c;
  int first_get = 0;
};

int map[5][5];
queue<int> new_numbers;

bool compare(RotateInfo a, RotateInfo b)
{
  if (a.first_get == b.first_get)
  {
    if (a.angle == b.angle)
    {
      if (a.c == b.c)
      {
        return a.r < b.r;
      }
      return a.c < b.c;
    }
    return a.angle < b.angle;
  }
  return a.first_get > b.first_get;
}

void rotate(int before_rotate[3][3], int r, int c)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      map[r - 1 + i][c - 1 + j] = before_rotate[3 - j - 1][i];
    }
  }

  return;
}

int calculate_first_get()
{
  vector<vector<int>> visited(5, vector<int>(5, 0));
  int value = 0;

  int move_r[4] = {0, 1, 0, -1};
  int move_c[4] = {1, 0, -1, 0};

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      int cnt = 0;
      int num = 0;

      queue<pair<int, int>> to_visit;

      if (visited[i][j] == 0)
      {
        to_visit.push(make_pair(i, j));
        visited[i][j] = 1;
        num = map[i][j];
        cnt++;
      }

      while (!to_visit.empty())
      {
        pair<int, int> front = to_visit.front();
        to_visit.pop();

        for (int k = 0; k < 4; k++)
        {
          if (front.first + move_r[k] >= 0 && front.first + move_r[k] < 5 && front.second + move_c[k] >= 0 && front.second + move_c[k] < 5)
          {
            if (visited[front.first + move_r[k]][front.second + move_c[k]] == 0)
            {
              if (map[front.first + move_r[k]][front.second + move_c[k]] == num)
              {
                to_visit.push(make_pair(front.first + move_r[k], front.second + move_c[k]));
                visited[front.first + move_r[k]][front.second + move_c[k]] = 1;
                cnt++;
              }
            }
          }
        }
      }

      if (cnt >= 3)
      {
        value += cnt;
      }
    }
  }

  return value;
}

RotateInfo choose_rotate()
{

  vector<RotateInfo> rotate_candidate;

  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= 3; j++)
    {
      // 원래 맵의 값들 저장
      int before_rotate[3][3] = {
          0,
      };

      for (int k = 1; k <= 3; k++)
      { // 3번 회전
        for (int r = 0; r < 3; r++)
        {
          for (int c = 0; c < 3; c++)
          {
            before_rotate[r][c] = map[i - 1 + r][j - 1 + c];
          }
        }

        RotateInfo new_info;

        rotate(before_rotate, i, j);

        new_info.first_get = calculate_first_get();
        new_info.angle = 90 * k;
        new_info.r = i;
        new_info.c = j;

        rotate_candidate.push_back(new_info);
      }

      // 원래 맵으로 돌아오기
      for (int r = 0; r < 3; r++)
      {
        for (int c = 0; c < 3; c++)
        {
          before_rotate[r][c] = map[i - 1 + r][j - 1 + c];
        }
      }

      rotate(before_rotate, i, j);
    }
  }

  // 회전 방법 선택
  sort(rotate_candidate.begin(), rotate_candidate.end(), compare);
  return rotate_candidate[0];
}

int get_ruins()
{
  // 획득 가능한 유물 획득
  vector<vector<int>> visited(5, vector<int>(5, 0));
  int value = 0;
  vector<pair<int, int>> erase;

  queue<pair<int, int>> to_visit;

  int move_r[4] = {0, 1, 0, -1};
  int move_c[4] = {1, 0, -1, 0};

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      int cnt = 0;
      int num = 0;
      vector<pair<int, int>> get_idx;

      if (visited[i][j] == 0)
      {
        to_visit.push(make_pair(i, j));
        get_idx.push_back(make_pair(i, j));
        visited[i][j] = 1;
        num = map[i][j];
        cnt++;
      }

      while (!to_visit.empty())
      {
        pair<int, int> front = to_visit.front();
        to_visit.pop();

        for (int k = 0; k < 4; k++)
        {
          if (front.first + move_r[k] >= 0 && front.first + move_r[k] < 5 && front.second + move_c[k] >= 0 && front.second + move_c[k] < 5)
          {
            if (visited[front.first + move_r[k]][front.second + move_c[k]] == 0)
            {
              if (map[front.first + move_r[k]][front.second + move_c[k]] == num)
              {
                to_visit.push(make_pair(front.first + move_r[k], front.second + move_c[k]));
                get_idx.push_back(make_pair(front.first + move_r[k], front.second + move_c[k]));
                visited[front.first + move_r[k]][front.second + move_c[k]] = 1;
                cnt++;
              }
            }
          }
        }
      }

      if (cnt >= 3)
      {
        value += cnt;
        erase.insert(erase.end(), get_idx.begin(), get_idx.end());
      }
    }
  }

  // 획득한 유물 지우기
  for (int i = 0; i < erase.size(); i++)
  {
    map[erase[i].first][erase[i].second] = 0;
  }

  return value;
}

// 유물 채우기
void fill_ruins()
{
  for (int j = 0; j < 5; j++)
  {
    for (int i = 4; i >= 0; i--)
    {
      if (map[i][j] == 0)
      {
        int front = new_numbers.front();
        map[i][j] = front;

        new_numbers.pop();
        new_numbers.push(front);
      }
    }
  }
}

int main()
{

  int k = 0;
  int m = 0;

  cin >> k >> m;

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < m; i++)
  {
    int input = 0;
    cin >> input;
    new_numbers.push(input);
  }

  for (int i = 0; i < k; i++)
  {
    int answer = 0;

    // 회전하기
    RotateInfo rotate_way = choose_rotate();

    int before_rotate[3][3] = {
        0,
    };

    if (rotate_way.first_get == 0)
    {
      break;
    }

    for (int t = 1; t <= rotate_way.angle / 90; t++)
    {
      for (int r = 0; r < 3; r++)
      {
        for (int c = 0; c < 3; c++)
        {
          before_rotate[r][c] = map[rotate_way.r - 1 + r][rotate_way.c - 1 + c];
        }
      }

      rotate(before_rotate, rotate_way.r, rotate_way.c);
    }

    // 유물 획득이 가능할 때까지 유물 획득
    while (true)
    {
      int now_value = get_ruins();

      // 획득 가능한 유물 없으면 멈춤
      if (now_value == 0)
      {
        break;
      }

      // 유물 가치 합산
      answer += now_value;

      // 유물 채우기
      fill_ruins();
    }

    if (answer != 0)
    {
      cout << answer << " ";
    }
  }

  return 0;
}