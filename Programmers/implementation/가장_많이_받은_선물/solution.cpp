#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(string input)
{
  vector<string> result;

  int pos = input.find(" ");

  result.push_back(input.substr(0, pos));
  result.push_back(input.substr(pos + 1, input.length()));

  return result;
}

int solution(vector<string> friends, vector<string> gifts)
{
  int answer = 0;

  // a -> b 선물 개수 누적 변수
  map<pair<string, string>, int> giftToFrom;

  // key값 임시 저장 tmp 변수
  pair<string, string> toFromKey;

  // 선물지수 계산을 위한 배열 (0: 내가 준 선물, 1: 받은 선물)
  int giftPoint[51][2] = {0};
  int friendIdx = -1;

  vector<string> splitResult;

  // gifts 순회하면서 선물 개수 누적 -> 해시맵에 저장
  for (int i = 0; i < gifts.size(); i++)
  {
    splitResult = split(gifts[i]);
    toFromKey = make_pair(splitResult[0], splitResult[1]);

    // 선물지수 계산을 위한 count 저장
    friendIdx = find(friends.begin(), friends.end(), splitResult[0]) - friends.begin();
    giftPoint[friendIdx][0]++;

    friendIdx = find(friends.begin(), friends.end(), splitResult[1]) - friends.begin();
    giftPoint[friendIdx][1]++;

    // map에 toFrom 기록 누적
    if (giftToFrom.find(toFromKey) != giftToFrom.end())
    {
      int giftCount = giftToFrom.find(toFromKey)->second;
      giftToFrom.erase(toFromKey);
      giftToFrom.insert({toFromKey, ++giftCount});
    }
    else
    {
      giftToFrom.insert({toFromKey, 1});
    }
  }

  // 각자 받을 선물 수를 저장하는 배열
  int getGiftCount[51] = {0};

  // 모든 friend 조합을 탐색
  for (int i = 0; i < friends.size(); i++)
  {
    // 겹쳐서 세는 경우 없도록 인덱스 조절
    for (int j = i + 1; j < friends.size(); j++)
    {
      // a -> b 방향 선물 개수 찾기
      pair<string, string> key1 = make_pair(friends[i], friends[j]);
      int giftCount1 = 0;

      if (giftToFrom.find(key1) != giftToFrom.end())
      {
        giftCount1 = giftToFrom.find(key1)->second;
      }

      // b -> a 방향 선물 개수 찾기
      pair<string, string> key2 = make_pair(friends[j], friends[i]);
      int giftCount2 = 0;

      if (giftToFrom.find(key2) != giftToFrom.end())
      {
        giftCount2 = giftToFrom.find(key2)->second;
      }

      // 선물을 받는 사람 결정
      if (giftCount1 > giftCount2)
      {
        getGiftCount[i]++;
      }
      else if (giftCount1 < giftCount2)
      {
        getGiftCount[j]++;
      }
      else
      { // 선물 지수로 판단해야하는 경우
        int point1 = giftPoint[i][0] - giftPoint[i][1];
        int point2 = giftPoint[j][0] - giftPoint[j][1];

        if (point1 > point2)
        {
          getGiftCount[i]++;
        }
        else if (point1 < point2)
        {
          getGiftCount[j]++;
        }
      }
    }
  }

  // 최댓값 찾아내기
  for (int i = 0; i < friends.size(); i++)
  {
    if (answer < getGiftCount[i])
    {
      answer = getGiftCount[i];
    }
  }

  return answer;
}