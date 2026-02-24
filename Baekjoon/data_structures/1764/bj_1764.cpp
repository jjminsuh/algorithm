#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

    int n = 0;
    int m = 0;

    cin >> n >> m;

    // 듣도 못한 사람 저장
    set<string> never_heard;

    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        never_heard.insert(input);
    }

    // 보도 못한 사람 중 듣도 못한 사람 출력
    set<string> answer;

    for(int i = 0; i < m; i++) {
        string input;
        cin >> input;

        if(never_heard.find(input) != never_heard.end()) {
            answer.insert(input);
        }
    }

    cout << answer.size() << "\n";

    for(auto name: answer) {
        cout << name << "\n";
    }

    return 0;
}