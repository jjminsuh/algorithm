#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int n = 0;

    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    stack<pair<int, int>> ascending_stack;
    vector<int> answer(n, -1);

    for(int i = 0; i < n; i++) {
        // 새로운 숫자와 stack의 top 비교
        while(!ascending_stack.empty()) {
            pair<int, int> top = ascending_stack.top();
            // 더 큰 경우 pop하고 answer 채워 넣기
            if(nums[i] > top.second) {
                ascending_stack.pop();
                answer[top.first] = nums[i];
            } else { // 새로운 숫자가 더 작은 경우 멈춤
                break;
            }
        }

        // 새로운 숫자 stack에 넣기
        ascending_stack.push(make_pair(i, nums[i]));
    }

    for(int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}