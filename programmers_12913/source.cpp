#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int max = 0;
    int pre_idx;
    for (int i=0;i<4;i++)
    {
        if (max < land[0][i])
        {
            max = land[0][i];
            pre_idx = i;
        }
    }
    answer = max;
    

    for (int i = 1; i < land.size(); i++)
    {
        max = 0;
        for (int col = 0; col < 4; col++)
        {
            if (col == pre_idx)
                continue;
            if (max < land[i][col])
            {
                max = land[i][col];
                pre_idx = col;
            }
        }
        answer += max;
    }

    return answer;
}