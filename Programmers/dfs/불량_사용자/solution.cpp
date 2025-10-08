#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<set<string> > found;

bool check_is_banned(string user, string banned) {
    if(user.length() != banned.length()) {
        return false;
    }
    
    for(int i = 0; i < banned.size(); i++) {
        if(banned[i] == '*') {
            continue;
        }
        
        if(banned[i] != user[i]) {
            return false;
        }
    }
    
    return true;
}

void dfs(int depth, set<string> banned_user, vector<string> &user_id, vector<string> &banned_id) {
    if(depth >= banned_id.size()) {
        if(banned_user.size() == banned_id.size()) {
            found.insert(banned_user);
        }
        
        return;
    }
    
    
    for(int i = 0; i < user_id.size(); i++) {
        if(banned_user.find(user_id[i]) != banned_user.end()) {
            continue;
        }
        
        if(check_is_banned(user_id[i], banned_id[depth])) {
            banned_user.insert(user_id[i]);
            dfs(depth + 1, banned_user, user_id, banned_id);
            banned_user.erase(user_id[i]);
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    set<string> id;
    
    dfs(0, id, user_id, banned_id);
    
    answer = found.size();
    
    return answer;
}