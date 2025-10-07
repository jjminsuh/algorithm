#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // 그리디로 접근
    // 멀리 있는 집들에게 먼저 배달
    int del_idx = n - 1;
    int pick_idx = n - 1;
    bool is_breaked = false;
    
    for(int i = n - 1; i >= 0; i--) {
        if(deliveries[i] != 0) {
            del_idx = i;
            is_breaked = true;
            break;
        }
    }
    
    if(!is_breaked) {
        del_idx = -1;
    }
    
    is_breaked = false;
    for(int i = n - 1; i >= 0; i--) {
        if(pickups[i] != 0) {
            pick_idx = i;
            is_breaked = true;
            break;
        }
    }
    
    if(!is_breaked) {
        pick_idx = -1;
    }
    
    while(del_idx >= 0 || pick_idx >= 0) {  
        int max_idx = max(del_idx, pick_idx);
        
        answer += (max_idx + 1) * 2;
        
        long long sum = 0;
        is_breaked = false;
        for(int i = del_idx; i >= 0; i--) {
            if(sum + deliveries[i] <= cap) {
                sum += deliveries[i];
            } else {
                deliveries[i] = deliveries[i] - (cap - sum);
                del_idx = i;
                is_breaked = true;
                break;
            }
        }
        
        if(!is_breaked) {
            del_idx = -1;
        }
        
        sum = 0;
        is_breaked = false;
        for(int i = pick_idx; i >= 0; i--) {
            if(sum + pickups[i] <= cap) {
                sum += pickups[i];
            } else {
                pickups[i] = pickups[i] - (cap - sum);
                pick_idx = i;
                is_breaked = true;
                break;
            }
        }
        
        if(!is_breaked) {
            pick_idx = -1;
        }
    }
    
    return answer;
}