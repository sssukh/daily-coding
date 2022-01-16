#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    /*
    int start_row = left / n;
    int start_col = left % n;
    int end_row = right / n;
    int end_col = right % n;

    if (start_col <= start_row)
    {
        vector<int> tmp(start_row - start_col, start_row + 1);
        answer.insert(answer.begin(), tmp.begin(), tmp.end());
    }
    

    //answer.insert(answer.end(), source.begin() + start_col, source.end());
    for (int i = start_col; i < n; i++)
    {
        answer.push_back(i + 1);
    }

    for (int i = start_row + 1; i < end_row;i++)
    {
        vector<int> tmp2(i + 1, i + 1);
        answer.insert(answer.end(), tmp2.begin(), tmp2.end());
        //answer.insert(answer.end(), source.begin() + i + 1, source.end());
        for (int j = i + 1; j < n; j++)
        {
            answer.push_back(j + 1);
        }
    }
    
    if (end_row >= end_col)
    {
        vector<int> tmp3(end_col + 1, end_row + 1);
        answer.insert(answer.end(), tmp3.begin(), tmp3.end());
    }
    else
    {
        vector<int> tmp4(end_row + 1, end_row + 1);
        answer.insert(answer.end(), tmp4.begin(), tmp4.end());

        //answer.insert(answer.end(), source.begin() + end_row + 1, source.begin() + end_col+1);
        for (int i = end_row + 1; i <= end_col; i++)
        {
            answer.push_back(i + 1);
        }
    }
    */
    for (long long current = left; current <= right; current++)
    {
        int row = current / n;
        int col = current % n;
        if (row >= col)
            answer.push_back(row + 1);
        else
            answer.push_back(col + 1);
    }

    return answer;
}