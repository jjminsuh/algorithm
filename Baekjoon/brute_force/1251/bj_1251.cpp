#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reverse(string input)
{
    string result = "";

    for (int i = input.length() - 1; i >= 0; i--)
    {
        result += input[i];
    }

    return result;
}

int main()
{

    string input;

    cin >> input;

    int len = input.length();
    vector<string> words;

    for (int i = 1; i < input.length() - 1; i++)
    {
        for (int j = i + 1; j < input.length(); j++)
        {
            string first = input.substr(0, i - 0);
            string second = input.substr(i, j - i);
            string third = input.substr(j, len);

            string first_reverse = reverse(first);
            string second_reverse = reverse(second);
            string third_reverse = reverse(third);

            string new_word = first_reverse + second_reverse + third_reverse;

            words.push_back(new_word);
        }
    }

    sort(words.begin(), words.end());

    cout << words[0];

    return 0;
}