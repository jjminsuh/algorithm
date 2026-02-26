#include <iostream>
#include <string>

using namespace std;

int main() {

    string input;

    getline(cin, input);

    // 앞쪽 공백 제거
    int idx = 0;
    while(idx < input.length()) {
        if(input[idx] != ' ') {
            break;
        }

        idx++;
    }

    // 전체 공백인 경우
    if(idx >= input.length()) {
        cout << 0;
        return 0;
    }

    input = input.substr(idx);

    // 뒤쪽 공백 제거
    idx = input.length() - 1;
    while(idx >= 0) {
        if(input[idx] != ' ') {
            break;
        }

        idx--;
    } 

    input = input.substr(0, idx + 1);


    int cnt = 0;

    // 중복 공백 처리
    char before = input[0];
    for(int i = 1; i < input.length(); i++) {
        if(input[i] == ' ' && before != ' ') {
            cnt++;
        }

        before = input[i];
    }

    cout << cnt + 1;

    return 0;
}