#include <string>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int solution(vector<int> a) {
    int answer = 0;
    int left_min = a.front();
    vector<pair<int, int>> right;
    for (int i = 0; i < a.size(); i++)
    {
        right.push_back(make_pair(a[i], i));
    }
    sort(right.begin(), right.end(), cmp);
    for (int i = 0; i < a.size(); i++)
    {
        if (left_min >= a[i])
        {
            answer++;
            left_min = a[i];
            continue;
        }
        while (!right.empty()&&right.back().second <= i)
        {
            right.pop_back();
        }
        if (right.empty()||right.back().first > a[i])
            answer++;
    }

    return answer;
}