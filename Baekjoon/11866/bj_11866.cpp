#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {

    int n;
    int k;
    queue<int> people;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        people.push(i + 1);
    }

    printf("<");

    while(!people.empty()) {
        for(int i = 1; i < k; i++) {
            int tmp = people.front();
            people.pop();
            people.push(tmp);
        }

        int tmp = people.front();
        people.pop();

        if(people.empty()) {
            printf("%d", tmp);
        } else {
            printf("%d, ", tmp);
        }
    }

    printf(">");

    return 0;
}