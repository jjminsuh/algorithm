#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

    int n = 0;
    vector<int> stack;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int method = 0;
        scanf("%d", &method);

        if(method == 1) {
            int x = 0;
            scanf(" %d", &x);
            stack.push_back(x);
        } else if(method == 2) {
            if(stack.size() > 0) {
                printf("%d\n", stack.back());
                stack.pop_back();
            } else {
                printf("%d\n", -1);
            }
        } else if(method == 3) {
            printf("%lu\n", stack.size());
        } else if(method == 4) {
            printf("%d\n", stack.empty());
        } else if (method == 5) {
            if(stack.size() > 0) {
                printf("%d\n", stack.back());
            } else {
                printf("%d\n", -1);
            }
        }
    }

    return 0;
}