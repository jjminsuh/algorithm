#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string string1;
    string string2;

    cin >> string1;
    cin >> string2;

    int len1 = string1.length();
    int len2 = string2.length();

    // memo[i][j]: 문자열 1번의 i, 문자열 2번의 j 까지 고려했을 때의 LCS
    vector<vector<int>> memo(len1, vector<int>(len2, 0));

    // 초기화
    if(string1[0] == string2[0]) {
        memo[0][0] = 1;
    } else {
        memo[0][0] = 0;
    }

    for(int i = 1; i < string1.length(); i++) {
        if(string2[0] == string1[i]) {
            memo[i][0] = 1;
        } else {
            memo[i][0] = memo[i - 1][0];
        }
    }

    for(int j = 1; j < len2; j++) {
        if(string1[0] == string2[j]) {
            memo[0][j] = 1;
        } else {
            memo[0][j] = memo[0][j - 1];
        }
    }

    // memo 배열 채우기
    // 같은 경우 이전보다 부분 수열 길이 + 1
    for(int i = 1; i < len1; i++) {
        for(int j = 1; j < len2; j++) {
            if (string1[i] == string2[j]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    // 최댓값 찾기
    int max = 0;

    for (int i = 0; i < len1; i++) {
        if(max < memo[i][len2 - 1]) {
            max = memo[i][len2 - 1];
        }
    }

    for (int j = 0; j < len2; j++) {
        if(max < memo[len1 - 1][j]) {
            max = memo[len1 - 1][j];
        }
    }

    cout << max;

    return 0;
}