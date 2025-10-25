#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    // 가질 수 있는 가장 큰 값 넣기
    int answer = 200000001;
    
    // index를 저장
    // front가 start index, end가 end index가 되도록!
    deque<int> window;
    
    // window의 size가 k를 넘지 않도록 진행
    for(int i = 0; i < stones.size(); i++) {
        // i번째를 추가하기 위해 window의 크기 맞춰주기
        while(!window.empty()) {
            if(i - window.front() >= k) {
                window.pop_front();
            } else {
                break;
            }
        }
        
        // 새로 stone을 추가
        // 내가 추가하려는 곳에 나보다 작은 stone이 있으면 pop
        // 윈도우 안쪽에 나보다 작은 stone은 건너뛰기로 넘어 올 수 있기 때문
        while(!window.empty()) {
            if(stones[window.back()] < stones[i]) {
                window.pop_back();
            } else {
                break;
            }
        }
        
        // 새 stone 추가
        window.push_back(i);
        
        // 윈도우가 k개 포함하는 시점부터는 answer를 계산
        // 윈도우 가장 앞에 있는 stone이 내가 최대한 늦게 window를 맞추며 밟아야 하는 stone
        // 이걸 못 밟으면 더 이상 진행 불가 -> 그래서 이 값과 이전 answer 중 min을 고른다.
        if(i >= k - 1) {
            answer = min(answer, stones[window.front()]);
        }
    }
    
    // answer가 변하지 않은 경우 아무도 못가는 입력이 주어졌으므로 answer = 0
    if(answer == 200000001) {
        answer = 0;
    }
    
    return answer;
}