#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{

    int row = arr1.size();
    int mul = arr1[0].size();
    int col = arr2[0].size();

    vector<vector<int>> answer(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int res = 0;
            for (int k = 0; k < mul; k++)
            {
                res += arr1[i][k] * arr2[k][j];
            }

            answer[i][j] = res;
        }
    }

    return answer;
}