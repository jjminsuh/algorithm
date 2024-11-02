#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

void isPerfectString(string input) {

    stack<char> bracket;
    bool isPerfect = true;
    int i = 0;

    while(1) {
        if(input[i] == '.') {
            break;
        }

        if(input[i] == '(') {
            bracket.push('(');
        } else if (input[i] == ')') {
            if(bracket.empty()) {
                isPerfect = false;
            } else if(bracket.top() != '(') {
                isPerfect = false;
                bracket.pop();
            } else {
                bracket.pop();
            }
        } else if(input[i] == '[') {
            bracket.push('[');
        } else if(input[i] == ']') {
            if(bracket.empty()) {
                isPerfect = false;
            } else if(bracket.top() != '[') {
                isPerfect = false;
                bracket.pop();
            } else {
                bracket.pop();
            }
        }

        i++;
    }

    if(bracket.empty() && isPerfect) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

}

int main() {

    string inputLine;
    char input[100];
    char tmp;

    while(1) {
        scanf("%[^\n]", input);
        scanf("%c", &tmp);

        inputLine = input;

        if(inputLine == ".") {
            return 0;
        } else {
            isPerfectString(inputLine);
        }
    }

    return 0;
}