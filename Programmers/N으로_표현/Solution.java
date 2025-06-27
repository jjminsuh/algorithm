import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = -1;
        
        Set<Integer>[] memo = new HashSet[9];
        
        memo[1] = new HashSet<Integer>();
        memo[1].add(N);
        
        if(number == N) {
            answer = 1;
            return answer;
        }
        
        for(int i = 2; i <= 8; i++) {
            Set<Integer> possibleNum = new HashSet<Integer>();
            
            // 연달아 이어붙인 값
            String NString = Integer.toString(N);
            NString = NString.repeat(i);
            possibleNum.add(Integer.parseInt(NString));
            
            for(int j = 1; j < i; j++) {
                for(Integer num1: memo[j]) {
                    for(Integer num2: memo[i - j]) {
                        // 더하기
                        possibleNum.add(num1 + num2);
                        
                        // 빼기
                        possibleNum.add(num1 - num2);
                        
                        // 곱하기
                        possibleNum.add(num1 * num2);
                        
                        // 나누기
                        if(num2 != 0) {
                            possibleNum.add(num1 / num2);
                        }
                    }
                }
            }
            
            if(possibleNum.contains(number)) {
                answer = i;
                break;
            }
            
            memo[i] = possibleNum;
        }
        
        return answer;
    }
}