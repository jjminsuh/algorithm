#include <string>
#include <iostream>

using namespace std;

int main() {

    string input;

    while(getline(cin, input)) {
        printf("%s\n", input.c_str());
    }

    return 0;
}