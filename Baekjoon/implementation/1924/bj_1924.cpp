#include <iostream>
#include <vector>

using namespace std;

int main() {

    int x = 0;
    int y = 0;

    scanf("%d %d", &x, &y);

    int days = 0;

    for(int i = 1; i < x; i++) {
        if(i == 2) {
            days = days + 28;
        } else if((i <= 7 && i % 2 == 1) || (i >= 8 && i % 2 == 0)) {
            days = days + 31;
        } else {
            days = days + 30;
        }
    }

    days = days + y;

    string dayTag[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    printf("%s", dayTag[days % 7].c_str());


    return 0;
}