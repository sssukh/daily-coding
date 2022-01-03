#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}




int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<int> stones_sort = stones;
    sort(stones_sort.begin(), stones_sort.end(),cmp);

    for (int i = 0; i < stones.size(); i++)
    {
        int current = stones_sort[i];
        int cnt = 0;
        for (int j = 0; j < stones.size(); j++)
        {
            if (stones[j] <= current)
                cnt++;
            else
                cnt = 0;
            if (cnt >= k)
                return current;
        }
    }
    
    

    return answer;
}