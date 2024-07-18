#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main() {

    int N = 0;
    int M = 0;

    int numTmp = 0;

    vector<int> A;
    deque<int> B;
    vector<int> inputNumbers;


    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf(" %d", &numTmp);
        A.push_back(numTmp);
    }

    for(int i = 0; i < N; i++) {
        scanf(" %d", &numTmp);
        if(A[i] == 0) {
            B.push_back(numTmp);
        }
    }

    scanf(" %d", &M);

    for(int i = 0;  i < M; i++) {
        scanf(" %d", &numTmp);
        inputNumbers.push_back(numTmp);
    }


    for(int i = 0; i < M; i++) {
        B.push_front(inputNumbers[i]);
    }

    for(int i = 0; i < M; i++) {
        int x = B.back();
        B.pop_back();

        printf("%d ", x);
    }


    return 0;
}