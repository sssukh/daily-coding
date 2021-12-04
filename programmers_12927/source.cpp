#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int cur_idx = 0;
    int worksSize = works.size();
    int current_works = 0;
    int total = 0;
    for (int i = 0; i < worksSize; i++)
        total += works[i];
    sort(works.begin(), works.end(), cmp);
    int max = works.back();
    for (int i = 1; i <= max; i++)
    {
        current_works += worksSize - cur_idx;
        if (n <total - current_works)
        {
            while (works[cur_idx] <= i)
            {
                cur_idx++;
                answer += i * i;
            }
        }
        else           
        {
            n -= total - current_works;
            for (int j = 1; j <= n; j++)
            {
                answer += (i - 1) * (i - 1);
            }
            for (int j = 0; j < worksSize - cur_idx - n; j++)
            {
                answer += i * i;
            }
            break;
        }
    }


    return answer;
}