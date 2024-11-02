#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

    vector<int> input;

    for(int i = 0; i < 6; i++) {
        int tmp = 0;
        scanf(" %d", &tmp);
        input.push_back(tmp);
    }

    int x = -999;
    int y = -999;

    for(x = -999; x <= 999; x++) {
        for(y = -999; y <= 999; y++) {
            if(((input[0] * x) + (input[1] * y) == input[2])
                && ((input[3] * x) + (input[4] * y) == input[5])) {
                    printf("%d %d", x, y);
                    return 0;
            }
        }
    }

    return 0;
}