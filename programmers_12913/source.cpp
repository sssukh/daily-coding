#include <vector>
using namespace std;

int max(int, int, int);


int solution(vector<vector<int> > land)
{
    int answer = 0;
    /*
    int max = 0;
    int previous_row_idx;
    for (int i=0;i<4;i++)
    {
        if (max < land[0][i])
        {
            max = land[0][i];
            previous_row_idx = i;
        }
    }
    answer = max;
    

    for (int i = 1; i < land.size(); i++)
    {
        max = 0;
        int pre_idx = 0;
        for (int col = 0; col < 4; col++)
        {
            if (col == previous_row_idx)
                continue;
            if (max < land[i][col])
            {
                max = land[i][col];
                pre_idx = col;
            }
        }
        answer += max;
        previous_row_idx = pre_idx;
    }
    */
    
    for (int i = 1; i < land.size(); i++)
    {
        land[i][0] += max(land[i - 1][1], land[i - 1][2], land[i - 1][3]);
        land[i][1] += max(land[i - 1][0], land[i - 1][2], land[i - 1][3]);
        land[i][2] += max(land[i - 1][1], land[i - 1][0], land[i - 1][3]);
        land[i][3] += max(land[i - 1][1], land[i - 1][2], land[i - 1][0]);

    }


    int tmp = max(land.back()[0], land.back()[1], land.back()[2]);

    return  tmp>land.back()[3]?tmp:land.back()[3];
}


int max(int a, int b, int c)
{
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}