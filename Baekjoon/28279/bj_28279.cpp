#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main() {

    int n = 0;
    deque<int> deque;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int method = 0;
        scanf("%d", &method);

        if(method == 1) {
            int value;
            scanf(" %d", &value);
            deque.push_front(value);
        } else if(method == 2) {
            int value;
            scanf(" %d", &value);
            deque.push_back(value);
        } else if(method == 3) {
            if(deque.empty()) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", deque.front());
                deque.pop_front();
            }
        } else if(method == 4) {
            if(deque.empty()) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", deque.back());
                deque.pop_back();
            }
        } else if(method == 5) {
            printf("%lu\n", deque.size());
        } else if(method == 6) {
            printf("%d\n", deque.empty());
        } else if(method == 7) {
            if(deque.empty()) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", deque.front());
            }
        } else if(method == 8) {
            if(deque.empty()) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", deque.back());
            }
        }
    }

    return 0;
}