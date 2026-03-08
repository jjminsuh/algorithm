#include <iostream>
#include <set>

using namespace std;

int main() {

    int a_cnt;
    int b_cnt;

    cin >> a_cnt >> b_cnt;

    set<int> set_all;

    for(int i = 0; i < a_cnt; i++) {
        int input;

        cin >> input;

        set_all.insert(input);
    }

    for(int i = 0; i < b_cnt; i++) {
        int input;

        cin >> input;

        set_all.insert(input);
    }

    int a_diff = set_all.size() - b_cnt;
    int b_diff = set_all.size() - a_cnt;

    cout << a_diff + b_diff;


    return 0;
}