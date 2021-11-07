#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> idx;
    int dungeonSize = dungeons.size();
    for (int i = 0; i < dungeonSize; i++)
    {
        idx.push_back(i);
    }

    do
    {
        int tmp = k;
        int n = 0;
        for (int i = 0; i < dungeonSize; i++)
        {
            if (tmp >= dungeons[idx[i]][0])
            {
                tmp -= dungeons[idx[i]][1];
                n++;
            }
        }
        if (answer < n)
            answer = n;
    } while (next_permutation(idx.begin(), idx.end()));



    return answer;
}

int main()
{
    solution(80, { {80,20} ,{50,40},{30,10} });
}