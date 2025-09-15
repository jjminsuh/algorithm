#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 카드 구조체 정의
struct CardItem
{
  int num;
  // 처음 뽑은 카드 중 짝꿍이 있는지
  bool has_pair_mine = false;
  // 이후에 뽑을 가능성이 있는 카드 중 짝꿍이 있는지
  bool has_pair_can_use = false;
};

// 우선순위 큐 우선순위 설정
struct compare
{
  bool operator()(CardItem &a, CardItem &b)
  {
    // 1. 기본에 카드 중 짝꿍이 존재하는 카드
    // 2. 뽑을 가능성이 있는 카드에 짝꿍이 존재하는 카드
    // 3. 카드 숫자가 더 큰 카드
    if (!a.has_pair_mine && !b.has_pair_mine)
    {
      if (!a.has_pair_can_use && !b.has_pair_can_use)
      {
        return a.num < b.num;
      }
      else if (a.has_pair_can_use)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    else if (a.has_pair_mine)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};

int solution(int coin, vector<int> cards)
{
  int answer = 0;

  int get_card_idx = 0;
  int n = cards.size();

  queue<pair<int, int>> has_pair;
  priority_queue<CardItem, vector<CardItem>, compare> can_use;
  // 기존 카드인지 확인하는 flag 배열
  vector<bool> is_my_card(n + 1, false);
  // 뽑을 수 있는 카드인지 확인하는 flag 배열
  vector<bool> is_can_use(n + 1, false);
  int initial_num = n / 3;

  // 초기에 갖고 있는 카드 설정
  // 자신의 짝꿍이 있는지만 확인
  for (int i = 0; i < initial_num; i++)
  {
    is_my_card[cards[i]] = true;
    get_card_idx++;

    // 짝꿍이 있는지 확인, 있으면 큐에 삽입
    if (is_my_card[(n + 1) - cards[i]])
    {
      has_pair.push(make_pair(cards[i], (n + 1) - cards[i]));
    }
  }

  // 1라운드 진행함
  answer++;

  while (get_card_idx < cards.size())
  {
    // 카드 두장을 들고 와서 can use에 저장
    CardItem new_card_1;
    new_card_1.num = cards[get_card_idx];
    is_can_use[new_card_1.num] = true;
    if (is_my_card[(n + 1) - new_card_1.num])
    {
      new_card_1.has_pair_mine = true;
    }
    else if (is_can_use[(n + 1) - new_card_1.num])
    {
      new_card_1.has_pair_can_use = true;
    }
    can_use.push(new_card_1);

    CardItem new_card_2;
    new_card_2.num = cards[get_card_idx + 1];
    is_can_use[new_card_2.num] = true;
    if (is_my_card[(n + 1) - new_card_2.num])
    {
      new_card_2.has_pair_mine = true;
    }
    else if (is_can_use[(n + 1) - new_card_2.num])
    {
      new_card_2.has_pair_can_use = true;
    }
    can_use.push(new_card_2);

    get_card_idx = get_card_idx + 2;

    // 이미 버릴 카드가 있는 경우
    if (!has_pair.empty())
    {
      pair<int, int> front = has_pair.front();
      has_pair.pop();

      is_my_card[front.first] = false;
      is_my_card[front.second] = false;

      answer++;

      continue;
    }

    // 새 카드를 들고와야하는 경우
    // 들고 올 수 있는 카드들 중에서 당장 버릴 수 있는 카드 들고 와야 함
    bool can_continue = false;
    vector<CardItem> use_later;
    while (!can_use.empty())
    {
      // 우선순위가 높은 카드부터 확인
      CardItem front = can_use.top();
      can_use.pop();

      // 기존 카드 중에 짝꿍이 있으면 coin 1개 차감
      if (front.has_pair_mine)
      {
        if (coin < 1)
        {
          break;
        }

        coin--;
        can_continue = true;
        answer++;
        break;
      }
      else
      { // 뽑을 수 있는 카드 중 짝꿍이 있는 경우에는 coin 2개를 차감
        if (front.has_pair_can_use)
        {
          // 먼저 들어간 카드가 있어도 뒷쪽 짝꿍에서 걸려서 놓치는 경우 없을거임
          // 둘 다 사용 가능한 카드인지 확인
          if (is_can_use[front.num] && is_can_use[(n + 1) - front.num])
          {
            if (coin < 2)
            {
              break;
            }

            coin -= 2;
            can_continue = true;
            answer++;
            is_can_use[front.num] = false;
            is_can_use[(n + 1) - front.num] = false;
            break;
          }
          else
          {
            // 우선순위 높아도 사용 불가능한 카드가 있으면 잠시 빼놨다가 다시 큐에 넣어줌
            use_later.push_back(front);
          }
        }
      }
    }

    if (!can_continue)
    {
      break;
    }

    for (int i = 0; i < use_later.size(); i++)
    {
      can_use.push(use_later[i]);
    }
  }

  return answer;
}