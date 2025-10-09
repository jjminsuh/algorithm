#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 0};
    int min_length = gems.size();
    
    set<string> distinct_gems;
    int total_gem = 0;
    
    for(int i = 0; i < gems.size(); i++) {
        distinct_gems.insert(gems[i]);
    }
    
    total_gem = distinct_gems.size();
    
    int start = 0;
    int end = gems.size() - 1;
    
    map<string, int> bought_gems;

    // 모들 보석을 살 때까지 end 증가
    for(int i = start; i < gems.size(); i++) {
        if(bought_gems.size() == total_gem) {
            end = i - 1;
            break;
        }

        if(bought_gems.find(gems[i]) != bought_gems.end()) {
            bought_gems[gems[i]] ++;
        } else {
            bought_gems.insert(make_pair(gems[i], 1));
        }
    }

    // start 당겨주기 -> 최소 길이 되도록
    for(int i = start; i <= end; i++) {
        if(bought_gems[gems[i]] == 1) {
            start = i;
            break;
        }

        bought_gems[gems[i]]--;
    }

    if(min_length > (end - start) && bought_gems.size() == total_gem) {
        answer[0] = start + 1;
        answer[1] = end + 1;
        min_length = end - start;
    }
        
    while(end < gems.size()) {
        // start에 갖고 있는 gem 제거
        if(bought_gems[gems[start]] == 1) {
            bought_gems.erase(gems[start]);
        } else {
            bought_gems[gems[start]] --;
        }
        
        // window 밀기
        start = start + 1;
        end = end + 1;
        
        // 모든 보석 포함할때까지 end 밀기
        for(int i = end; i < gems.size(); i++) {
            if(bought_gems.size() == total_gem) {
                end = i - 1;
                break;
            }
            
            if(bought_gems.find(gems[i]) != bought_gems.end()) {
                bought_gems[gems[i]] ++;
            } else {
                bought_gems.insert(make_pair(gems[i], 1));
            }
        }
        
        if(end > gems.size() || bought_gems.size() != total_gem) {
            break;
        }
        
        // start 당겨주기 -> 최소 길이 되도록
        for(int i = start; i <= end; i++) {
            if(bought_gems[gems[i]] == 1) {
                start = i;
                break;
            }
            
            bought_gems[gems[i]]--;
        }
        
        if(min_length > (end - start) && bought_gems.size() == total_gem) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            min_length = end - start;
        }
    }
    
    
    return answer;
}