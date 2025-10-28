#include <string>
#include <vector>
#include <queue>

using namespace std;

struct MusicInfo{
    string title;
    vector<string> music;
};

// 음악 길이 계산 함수
int calculate_duration(int start_h, int start_m, int end_h, int end_m) {
    int duration = 0;
    
    if(end_m - start_m < 0) {
        end_h--;
        end_m = 60 + end_m;
    }
    
    duration += end_m - start_m;
    duration += (end_h - start_h) * 60;
    
    return duration;
}

// string으로 주어진 음악 정보 split
MusicInfo split_music_info(string info) {
    MusicInfo new_music;
    
    vector<string> tokens;
    string tmp = "";
    for(int i = 0; i < info.length(); i++) {
        if(info[i] == ',') {
            tokens.push_back(tmp);
            tmp = "";
        } else {
            tmp += info[i];
        }
    }
    
    tokens.push_back(tmp);
    
    int start_h = stoi(tokens[0].substr(0, 2));
    int start_m = stoi(tokens[0].substr(3, 2));
    int end_h = stoi(tokens[1].substr(0, 2));
    int end_m = stoi(tokens[1].substr(3, 2));
    
    int duration = calculate_duration(start_h, start_m, end_h, end_m);
    
    new_music.title = tokens[2];
    
    // 기본 곡의 음 패턴 추출
    queue<string> music_pattern;
    tmp = "";
    int idx = 0;
    while(idx < tokens[3].size()) {
        if(tokens[3][idx] >= 'A' && tokens[3][idx] <= 'G') {
            if(idx + 1 < tokens[3].size()) {
                if(tokens[3][idx + 1] < 'A' || tokens[3][idx + 1] > 'G') {
                    tmp += tokens[3][idx];
                    tmp += tokens[3][idx + 1];
                    music_pattern.push(tmp);
                    tmp = "";
                    idx += 2;
                } else {
                    tmp += tokens[3][idx];
                    music_pattern.push(tmp);
                    tmp = "";
                    idx += 1;
                }
            } else {
                tmp += tokens[3][idx];
                music_pattern.push(tmp);
                tmp = "";
                idx += 1;
            }
        }
    }
    
    // duration에 맞게 실제 재생된 pattern 저장
    vector<string> music;
    for(int i = 0; i < duration; i++) {
        string front = music_pattern.front();
        music_pattern.pop();
        music.push_back(front);
        music_pattern.push(front);
    }
    
    new_music.music = music;
    
    return new_music;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    vector<MusicInfo> music;
    
    // 곡 정보 추출
    for(int i = 0; i < musicinfos.size(); i++) {
        MusicInfo new_music = split_music_info(musicinfos[i]);
        music.push_back(new_music);
    }
    
    // 들은 패턴을 배열 형태로 저장
    vector<string> heard;
    string tmp = "";
    int idx = 0;
    while(idx < m.size()) {
        if(m[idx] >= 'A' && m[idx] <= 'G') {
            if(idx + 1 < m.size()) {
                if(m[idx + 1] < 'A' || m[idx + 1] > 'G') {
                    tmp += m[idx];
                    tmp += m[idx + 1];
                    heard.push_back(tmp);
                    tmp = "";
                    idx += 2;
                } else {
                    tmp += m[idx];
                    heard.push_back(tmp);
                    tmp = "";
                    idx += 1;
                }
            } else {
                tmp += m[idx];
                heard.push_back(tmp);
                tmp = "";
                idx += 1;
            }
        }
    }
    
    
    int max_length = 0;
    int max_duration = 0;
    
    // 모든 음악에 대해서 매칭 진행
    for(int i = 0; i < music.size(); i++) {
        vector<string> info_pattern = music[i].music;
        vector<int> match_start_ids;
        
        // 들은 패턴의 시작점이 될 수 있는 idx 저장
        for(int j = 0; j < info_pattern.size(); j++) {
            if(info_pattern[j] == heard[0]) {
                match_start_ids.push_back(j);
            }
        }
        
        // 각 시작점에 대해서 max_length를 계산
        // 가장 긴 경우를 저장
        for(int j = 0; j < match_start_ids.size(); j++) {
            int length = 0;
            int heard_idx = 0;
            int match_idx = match_start_ids[j];
            bool is_stopped = false;
            
            while(heard_idx < heard.size()) {
                // 노래가 더 짧은 경우 아님!
                if(match_idx >= info_pattern.size()) {
                    is_stopped = true;
                    break;
                }
                
                // 들은 부분이 끝나지 않은 경우에도 해당 부분 아님
                if(info_pattern[match_idx] != heard[heard_idx]) {
                    is_stopped = true;
                    break;
                }
                
                length++;
                match_idx++;
                heard_idx++;
            }
            
            // 끝까지 탐색된 경우 -> 내가 들은 패턴이 모두 존재
            if(!is_stopped) {
                // 더 길이가 긴 경우 존재
                if(length > max_length) {
                    max_length = length;
                    answer = music[i].title;
                    max_duration = info_pattern.size();
                } else if(length == max_length) {
                    // 길이가 같으면 곡의 재생시간이 긴 곡을 저장
                    if(info_pattern.size() > max_duration) {
                        max_length = length;
                        answer = music[i].title;
                        max_duration = info_pattern.size();
                    }
                }
            }
        }
    }
    
    return answer;
}