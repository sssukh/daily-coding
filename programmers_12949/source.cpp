#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int row1 = arr1.size();
    int col1 = arr1[0].size();
    int col2 = arr2[0].size();

    for (int row = 0; row < row1; row++)
    {
        vector<int> row_vec;
        for (int i = 0; i < col2; i++)
        {
            int tmp = 0;
            for (int col = 0; col < col1; col++)
            {
                tmp += (arr1[row][col] * arr2[col][i]);
            }
            
            row_vec.push_back(tmp);
        }
        answer.push_back(row_vec);
    }

    return answer;
}