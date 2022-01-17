#include <string>
#include <vector>

using namespace std;

void zip(vector<vector<int>>& arr, int current_size,int row,int col, int& ones, int& zeros)
{
    if (current_size == 1)
    {
        if (arr[row][col])
            ++ones;
        else
            ++zeros;
        return;
    }
    int standard = arr[row][col];
    bool is_quit = false;
    for (int add_row = 0; is_quit==false&&add_row < current_size; add_row++)
    {
        for (int add_col = 0; add_col < current_size; add_col++)
        {
            if (arr[row + add_row][col + add_col] != standard)
            {
                is_quit = true;
                break;
            }
        }
    }
    if (is_quit)
    {
        zip(arr, current_size / 2, row, col, ones, zeros);
        zip(arr, current_size / 2, row + current_size / 2, col, ones, zeros);
        zip(arr, current_size / 2, row, col + current_size / 2, ones, zeros);
        zip(arr, current_size / 2, row + current_size / 2, col + current_size / 2, ones, zeros);
    }
    else
    {
        if (standard)
            ++ones;
        else
            ++zeros;
    }

    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int ones = 0;
    int zeros = 0;

    zip(arr, arr.size(), 0, 0, ones, zeros);
    answer.push_back(zeros);
    answer.push_back(ones);
    return answer;
}