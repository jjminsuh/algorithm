## 백준 1515 수 이어 쓰기

### 문제 설명

https://www.acmicpc.net/problem/1515

세준이는 1부터 N까지 모든 수를 차례대로 공백없이 한 줄에 다 썼다. 그리고 나서, 세준이가 저녁을 먹으러 나간 사이에 다솜이는 세준이가 쓴 수에서 마음에 드는 몇 개의 숫자를 지웠다.

세준이는 저녁을 먹으러 갔다 와서, 자기가 쓴 수의 일부가 지워져있는 모습을 보고 충격받았다.

세준이는 수를 방금 전과 똑같이 쓰려고 한다. 하지만, N이 기억이 나지 않는다.

남은 수를 이어 붙인 수가 주어질 때, N의 최솟값을 구하는 프로그램을 작성하시오. (아무것도 지우지 않을 수도 있다.)

#### 입력
첫째 줄에 지우고 남은 수를 한 줄로 이어 붙인 수가 주어진다. 이 수는 최대 3,000자리다.

#### 출력
가능한 N 중에 최솟값을 출력한다.

### 문제 접근

1부터 숫자를 늘려가면서 남은 숫자의 자리수가 존재하는 숫자에 도달하면 입력의 다음 자리수가 있는 숫자를 찾아나가는 방식으로 답을 찾아나가면 된다. (그리디 + 브루트포스)

### 코드 간단 설명
```
while input을 모두 탐색
  찾을 숫자를 string으로 변환

  for 찾을 숫자의 자릿수
    if 찾을 숫자의 자릿수가 input에 존재
      iter++
  
  min_num++ 로 다음 찾을 숫자 설정
```

#### 주의해야할 점
- 중간에 전체 입력 string 범위를 넘어갈 수 있으므로 내부에 if문으로 처리하여 넘어가는 경우 답을 return 하게 해줌

- while 나올 대 min_num 증가를 진행하므로 전체 탐색한 경우에는 -1한 값을  출력해준다.

- 숫자의 증감을 파악하여 N의 최소값을 찾는 방법을 시도했지만 이 경우 조건을 꼼꼼하게 확인하면서 다음 숫자를 계산해야한다. 너무 복잡하므로 이 방식이 더 적절한 풀이라고 생각함.