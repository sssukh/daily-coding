#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(int n, vector<int> weak, vector<int> dist) 
{
    int answer = -1;
    int weakSize=weak.size();
    vector<int> between_weak;
    between_weak.push_back((weak.front() - weak.back() + n)%n);
    for (int i = 1; i < weakSize; i++)
    {
        between_weak.push_back(weak[i] - weak[i - 1]);
    }
    sort(dist.begin(), dist.end(),cmp);
    if (weakSize == dist.size())
        answer = weakSize;
    for (int start_adder = 0; start_adder < weakSize; start_adder++)
    {
        int dist_idx = 0;
        int tmp = 0;
        bool hasJumped = false;
        int between_weak_idx;
        for (between_weak_idx = 0; between_weak_idx < weakSize; between_weak_idx++)
        {
            tmp += between_weak[(between_weak_idx + start_adder) % weakSize];
            if (tmp > dist[dist_idx])
            {
                if (hasJumped)
                    break;
                ++dist_idx;
                tmp = 0;
                hasJumped = true;
            }
            else
                hasJumped = false;
        }
        if (between_weak_idx == weakSize)
        {
            if (answer == -1 || answer > dist_idx)
                answer = dist_idx;
        }
    }

    return answer;
}

