#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
  int answer = 0;

  int max = 0;
  int second_max = 0;

  for (int i = 0; i < numbers.size(); i++)
  {
    if (numbers[i] > max)
    {
      second_max = max;
      max = numbers[i];
      continue;
    }

    if (numbers[i] > second_max)
    {
      second_max = numbers[i];
    }
  }

  answer = max * second_max;

  return answer;
}