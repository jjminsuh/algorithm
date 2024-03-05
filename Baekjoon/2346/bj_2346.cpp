#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main() {

    int n = 0;
    int numTmp = 0;
    // pair로 받으면 더 좋을 듯!!
    deque<int> numbers;
    deque<int> index;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf(" %d", &numTmp);
        numbers.push_back(numTmp);
        index.push_back(i + 1);
    }

    int popIdx = 1;
    int move = 0;

    while(!numbers.empty()) {
        if(move == 0) {
            popIdx = index.front();
            move = numbers.front();
            
            if(move > 0) {
                move--;
            }

            index.pop_front();
            numbers.pop_front();

            printf("%d ", popIdx);
        } else if(move > 0) {
            int tmp = index.front();
            index.pop_front();
            index.push_back(tmp);
            
            tmp = numbers.front();
            numbers.pop_front();
            numbers.push_back(tmp);
            
            move--;
        } else if(move < 0) {
            int tmp = index.back();
            index.pop_back();
            index.push_front(tmp);
            
            tmp = numbers.back();
            numbers.pop_back();
            numbers.push_front(tmp);
            
            move++;
        } 
    }

    return 0;
}
