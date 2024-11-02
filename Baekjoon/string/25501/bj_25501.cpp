#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int recursionCnt;

int recursion(const char *s, int l, int r){

    recursionCnt ++;

    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main() {

    int t = 0;
    char s[1000];

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%s", s);

        recursionCnt = 0;

        int isPalindromeResult = isPalindrome(s);

        printf("%d %d\n", isPalindromeResult, recursionCnt);
    }

    return 0;
}