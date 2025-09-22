package Programmers.dp.산_모양_타일링;

class Solution {
  public int solution(int n, int[] tops) {
    int answer = 0;

    // dp로 풀면 될 것 같음..!
    // 오른쪽이 삼각형 2개로 끝나는 경우 / 삼각형 1개로 끝나는 경우 / 평사로 끝나는 경우
    int[][] memo = new int[n + 1][3];

    memo[0][0] = 1;
    memo[0][1] = 0;
    memo[0][2] = 0;

    for (int i = 1; i <= n; i++) {
      if (tops[i - 1] == 1) {
        memo[i][0] = ((memo[i - 1][0] + memo[i - 1][1] + memo[i - 1][2]) * 2) % 10007;
        memo[i][1] = (memo[i - 1][0] + memo[i - 1][1]) % 10007;
        memo[i][2] = (memo[i - 1][0] + memo[i - 1][1] + memo[i - 1][2]) % 10007;
      } else {
        memo[i][0] = (memo[i - 1][0] + memo[i - 1][1] + memo[i - 1][2]) % 10007;
        memo[i][1] = (memo[i - 1][0] + memo[i - 1][1]) % 10007;
        memo[i][2] = (memo[i - 1][0] + memo[i - 1][1] + memo[i - 1][2]) % 10007;
      }
    }

    answer = (memo[n][0] + memo[n][1] + memo[n][2]) % 10007;

    return answer;
  }
}