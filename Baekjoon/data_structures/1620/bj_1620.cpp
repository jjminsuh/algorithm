#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;

    cin >> n >> m;

    map<string, int> pokemon_name;
    map<int, string> pokemon_num;

    for(int i = 1; i <= n; i++) {
        string name;
        cin >> name;

        pokemon_name.insert(make_pair(name, i));
        pokemon_num.insert(make_pair(i, name));
    }

    for(int i = 0; i < m; i++) {
        string input;
        cin >> input;

        bool is_num = true;

        for(int j = 0; j < input.length(); j++) {
            if(input[j] >= '0' && input[j] <= '9') {
                continue;
            } else {
                is_num = false;
                break;
            }
        }

        if(is_num) {
            int poke_num = stoi(input);

            cout << pokemon_num[poke_num] << "\n";
        } else {
            cout << pokemon_name[input] << "\n";
        }
    }


    return 0;
}