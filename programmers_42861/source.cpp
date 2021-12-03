#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int getParent(int a, vector<int>& connected)
{
    if (connected[a] == a)return a;
    else return connected[a] = getParent(connected[a], connected);
}
void Union(vector<int>& connected, int a,int b)
{
    a = getParent(a, connected);
    b = getParent(b, connected);
    if (a < b) connected[b] = a;
    else connected[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    vector<int> connected(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        connected[i] = i;
    }
    
    for (int i = 0; i < costs.size(); i++)
    {
        if (getParent(costs[i][0],connected) != getParent(costs[i][1],connected))
        {
            answer += costs[i][2];
            Union(connected, costs[i][0], costs[i][1]);
            count++;
        }
        if (count == n - 1)
            break;
    }

   
    return answer;
}