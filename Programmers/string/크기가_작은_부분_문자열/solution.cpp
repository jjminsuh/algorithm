#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
  int answer = 0;

  int start = 0;

  while (start <= t.length() - p.length())
  {
    string check = t.substr(start, p.length());

    // string으로 된 숫자 비교
    // 길이가 너무 길어서 int로 바꿔서 비교하는건 불가능!
    for (int i = 0; i < p.length(); i++)
    {
      if (i == p.length() - 1)
      {
        if (check[i] - '0' <= p[i] - '0')
        {
          answer++;
        }

        break;
      }

      if (check[i] - '0' < p[i] - '0')
      {
        answer++;
        break;
      }
      else if (check[i] - '0' > p[i] - '0')
      {
        break;
      }
    }

    start++;
  }

  return answer;
}