#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    vector<vector<int>
    int size = build_frame.size();
    for (int i = 0; i < size; i++)
    {
        vector<int> tmp = build_frame[i];
        if (tmp[2])     //보
        {
            if (tmp[3]) //설치
            {
                if (!tmp[1])
                {
                    auto iter = find(answer.begin(), answer.end(), { tmp[0] - 1,tmp[1],0,1 });
                }
            }
            else        //삭제
            {

            }
        }
        else            //기둥
        {
            if (tmp[3]) //설치
            {

            }
            else        //삭제
            {

            }
        }
    }

    return answer;
}