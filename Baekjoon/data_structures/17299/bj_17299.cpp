#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int n = 0;

    cin >> n;

    vector<int> nums(n);
    vector<int> num_count(1000001);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        num_count[nums[i]]++;
    }

    vector<int> f_nums(n);

    for(int i = 0; i < n; i++) {
        f_nums[i] = num_count[nums[i]];
    }

    // <index, <실제 숫자, count>> 형태로 저장
    stack<pair<int, pair<int, int>>> ascending_stack;
    vector<int> answer(n, -1);

    for(int i = 0; i < n; i++) {
        // 새로 들어온 f_num과 stack top의 f_num 비교
        while(!ascending_stack.empty()) {
            pair<int, pair<int, int>> top = ascending_stack.top();

            if(f_nums[i] > top.second.second) { // 더 크면 answer에 넣기
                ascending_stack.pop();
                answer[top.first] = nums[i];
            } else {
                break;
            }
        }

        ascending_stack.push(make_pair(i, make_pair(nums[i], f_nums[i])));
    }

    for(int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }


    return 0;
}