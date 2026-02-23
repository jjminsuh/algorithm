#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n = 0;

    cin >> n;

    vector<int> solution(n);

    for(int i = 0; i < n; i++) {
        cin >> solution[i];
    }

    sort(solution.begin(), solution.end());

    // 초기화
    int start = 0;
    int end = n - 1;
    int answer_first = solution[start];
    int answer_second = solution[end];
    int min_sum = abs(solution[start] + solution[end]);

    // 앞뒤에서 좁히면서 투포인터로 탐색
    while(start < end) {
        if(abs(solution[start + 1] + solution[end]) < abs(solution[start] + solution[end - 1])) {
            start += 1;
            
        } else {
            end -= 1;
        }

        if(start >= end) {
            break;
        }

        if (min_sum > abs(solution[start] + solution[end]))
        {
            answer_first = solution[start];
            answer_second = solution[end];
            min_sum = abs(solution[start] + solution[end]);
        }
    }

    cout << answer_first << " " << answer_second;
    

    return 0;
}