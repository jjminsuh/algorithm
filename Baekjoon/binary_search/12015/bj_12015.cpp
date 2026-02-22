#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> answer;
    // 초기화
    answer.push_back(nums[0]);

    for(int i = 1; i < n; i++) {
        // 새로운 수가 더 큰 수인 경우 바로 정답 수열에 추가
        if(answer[answer.size() - 1] < nums[i]) {
            answer.push_back(nums[i]);
            continue;
        }

        // 새로운 수가 더 큰 수가 아닌 경우 정답 수열에서 해당 수가 들어갈 위치의 숫자를 대치
        // 이진탐색으로 해당 수가 들어갈 위치 찾기
        int start = 0;
        int end = answer.size() - 1;

        int mid = (start + end) / 2;

        while(start < end) {
            mid = (start + end) / 2;
            if(nums[i] <= answer[mid]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        answer[start] = nums[i];
    }

    cout << answer.size();

    return 0;
}