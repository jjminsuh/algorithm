#include <string>

using namespace std;

int main() {

    char input = 0;
    int cnt = 0;

    while(scanf("%c", &input) != EOF) {

        if(cnt == 10) {
            cnt = 0;
            printf("\n%c", input);
            cnt++;
        } else {
            printf("%c", input);
            cnt++;
        }
    }

    return 0;
}