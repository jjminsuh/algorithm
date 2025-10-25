#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

using namespace std;

map<string, int> menu_combination;
set<string> visited;

// 가능한 모든 메뉴 조합 찾기
void combination(string order, string menus, int before) {
    // 주문의 길이가 될때까지 재귀적으로 반봅
    
    // 길이가 2이상인 조합은 menu_combination에 저장하며 주문한 사람의 수 누적
    if(menus.length() >= 2) {
        // 메뉴 구성 오름차순으로 정렬
        sort(menus.begin(), menus.end());
        
        // 이번 주문에서 본 적이 없는 메뉴 구성의 경우만 count
        if(visited.find(menus) == visited.end()) {
            visited.insert(menus);
        
            if(menu_combination.find(menus) != menu_combination.end()) {
                menu_combination[menus] += 1;
            } else {
                menu_combination.insert(make_pair(menus, 1));
            }
        }
    }
    
    // 모든 조합 순회
    for(int i = before + 1; i < order.length(); i++) {
        combination(order, menus + order[i], i);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<bool> course_size(11, false);
    vector<int> max_cnt(11, 0);
    
    // 모든 가능한 메뉴 구성 찾기
    for(int i = 0; i < orders.size(); i++) {
        visited.clear();
        combination(orders[i], "", -1);
    }
    
    for(int i = 0; i < course.size(); i++) {
        course_size[course[i]] = true;
    }
    
    // 각 가능한 코스 길이의 최대 주문 횟수 찾기
    for(auto iter = menu_combination.begin(); iter != menu_combination.end(); iter++) {
        if(iter->second >= 2) {
            if(max_cnt[iter->first.length()] < iter->second) {
                max_cnt[iter->first.length()] = iter -> second;
            }
        }
    }
    
    // 최대 주문 횟수랑 주문 횟수가 일치하는 코스만 answer에 저장
    for(auto iter = menu_combination.begin(); iter != menu_combination.end(); iter++) {
        if(iter->second >= 2) {
            if(course_size[iter->first.length()] && max_cnt[iter->first.length()] == iter->second) {
                answer.push_back(iter->first);
            }
        }
    }
    
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}