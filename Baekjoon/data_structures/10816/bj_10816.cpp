#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    map<int, int> numbers;

    for(int i = 0; i < n; i++) {
        int input;

        cin >> input;

        if(numbers.find(input) == numbers.end()) {
            numbers.insert(make_pair(input, 1));
        } else {
            numbers[input]++;
        }
    }

    int m;

    cin >> m;

    for(int i = 0; i < m; i++) {
        int input;

        cin >> input;

        if(numbers.find(input) == numbers.end()) {
            cout << "0 ";
        } else {
            cout << numbers[input] << " ";
        }
    }

    return 0;
}