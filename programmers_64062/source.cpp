#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 200000001
bool cmp(int a, int b)
{
    return a < b;
}




int solution(vector<int> stones, int k) {
    int answer = INF;
    vector<int> stones_sort = stones;
    sort(stones_sort.begin(), stones_sort.end(),cmp);

    int high = stones.size() - 1;
    int low = 0;
    int current;
    do
    {
        current = (high + low) / 2;
        int cnt = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (stones[i] <= stones_sort[current])
                cnt++;
            else
                cnt = 0;
            if (cnt >= k)
            {
                answer = stones_sort[current];
                high = current;
                break;
            }
        }
        if (cnt < k)
            low = current + 1;
        
    } while (low < high);

    return answer;
}