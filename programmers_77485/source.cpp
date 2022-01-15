#include <string>
#include <vector>
#include <iostream>

using namespace std;

int rotate(vector<int>& query, vector<vector<int>>& nums)
{
    int start_row = query[0];
    int start_col = query[1];
    int end_row = query[2];
    int end_col = query[3];

    int save;
    int current = nums[start_row + 1][start_col],min = current;

    for (int i = start_col; i <= end_col; i++)
    {
        save = nums[start_row][i];
        nums[start_row][i] = current;
        current = save;
        if (min > current)
            min = current;
    }
    for (int i = start_row + 1; i <= end_row; i++)
    {
        save = nums[i][end_col];
        nums[i][end_col] = current;
        current = save;
        if (min > current)
            min = current;
    }
    for (int i = end_col-1; i >= start_col; i--)
    {
        save = nums[end_row][i];
        nums[end_row][i] = current;
        current = save;
        if (min > current)
            min = current;
    }
    for (int i = end_row - 1; i > start_row; i--)
    {
        save = nums[i][start_col];
        nums[i][start_col] = current;
        current = save;
        if (min > current)
            min = current;
    }
    return min;
}



vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    vector<vector<int>> nums(rows+1,vector<int>(columns+1,0));
    int input = 0;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            nums[i][j] = ++input;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        answer.push_back(rotate(queries[i], nums));
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= columns; j++)
            {
                cout<<nums[i][j]<<" ";
            }
            cout << endl;
        }
    }


    return answer;
}