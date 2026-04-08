#include <iostream>

using namespace std;

void cantor(int start, int end, bool is_blank) {
    if(is_blank) {
        for(int i = start; i <= end; i++) {
            cout << " ";
        }
        
        return;
    }

    if(start == end) {
        cout << "-";
        return;
    }

    int gap = end - start + 1;

    cantor(start, start + (gap/3) - 1, false);
    cantor(start + (gap/3), start + (2 * (gap/3)) - 1, true);
    cantor(start + (2 * (gap/3)), end, false);
}

int cal_power(int n) {
    int result = 1;

    for(int i = 1; i <= n; i++) {
        result *= 3;
    }

    return result;
}

int main() {

    int n;

    while(cin >> n) {
        int target = cal_power(n);

        cantor(1, target, false);

        cout << "\n";
    }

    return 0;
}
