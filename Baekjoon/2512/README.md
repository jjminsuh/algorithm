## 백준 2512 예산

### 문제 설명

https://www.acmicpc.net/problem/2512

정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정

1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다. 

#### 입력
첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다. 다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 값들은 모두 1 이상 100,000 이하이다. 그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. M은 N 이상 1,000,000,000 이하이다. 

#### 출력
첫째 줄에는 배정된 예산들 중 최댓값인 정수를 출력한다. 

### 문제 접근

우선 예산을 정렬한다.

i. 전체 예산 요청이 예산 내인 경우

예산 요청 중 최댓값 반환

ii. 전체 예산 요청이 예산 밖인 경우

    1. (전체 예산 / 지방 개수) 이하의 예산을 가진 경우 예산을 다 줌 > 이분탐색 이용

    2. 남은 예산과 예산을 받지 못한 지방을 대상으로 i, ii를 반복

    3. 1을 적용할 수 있는 지방이 더 이상 없는 경우 나머지 지방에게 남은 액수를 똑같이 분배 (이때 받는 값이 상한액이 됨)

상한액을 정해야하는 상황이 되는 경우 상한액이 최댓값이 된다.

### 코드 간단 설명
```
while (ii - 1을 적용할 수 있는 경우)
  if(남은 예산 < 필요한 예산)
    예산 요청 중 최댓값 반환
  
  이분 탐색 진행하여 start_search에 예산이 (남은 예산 / 남은 지방 개수)보다 큰 가장 첫 번째 인덱스가 오도록 한다.

  모든 예산을 줄 수 있는 지방들의 예산 합을 계산하여 남은 예산 계산

ii-1을 더 이상 적용할 수 없는 순간이 되면 상한액인 (남은 예산 / 남은 지방 개수)를 반환한다
```

#### 주의해야할 점
- 처음에 전체 과정을 남은 예산을 가지고 여러번 반복할 수 있다는 사실을 모르고 ii를 한 번만 반복한 후 상한액을 계산했다. 1/n을 했을 때 모든 예산을 줄 수 있는 지방의 예산을 주고 남은 액수가 충분하면 전체 과정을 다시 적용할 수 있는 문제가 된다. (남은 금액과 남은 지방으로 같은 문제가 계속 정의될 수 있음)

- 이분 탐색이 끝나는 순간 start_search, mid, end_search에 어떤 인덱스가 오는지 잘 확인해야한다. 전체 예산을 줄 수 있는 지방의 바로 다음 인덱스가 무엇인지 필요한 상황(equal_money보다 큰 가장 작은 수의 인덱스)이므로 start_search가 해당 인덱스임을 알 수 있다.




