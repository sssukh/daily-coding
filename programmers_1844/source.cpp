#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct pos
{
    int x, y,dis;
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;

    vector<vector<int>> distances(maps.size(), vector<int>(maps[0].size(), 0));
    queue<struct pos> q;
    q.push({ 0,0,1 });
    while (!q.empty())
    {
        struct pos current = q.front();
        q.pop();
        cout << current.x << " " << current.y << " " << current.dis << endl;
        if (current.x >= 0 && current.x < maps.size() && 
            current.y >= 0 && current.y < maps[0].size() 
            && maps[current.x][current.y]==1&&distances[current.x][current.y]==0)
        {
            distances[current.x][current.y] = current.dis;
            q.push({ current.x + 1,current.y,current.dis + 1 });
            q.push({ current.x - 1,current.y,current.dis + 1 });
            q.push({ current.x,current.y + 1,current.dis + 1 });
            q.push({ current.x,current.y - 1,current.dis + 1 });
        }
    }
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }
    if (distances[maps.size() - 1][maps[0].size() - 1] > 0)
        answer = distances[maps.size() - 1][maps[0].size() - 1];
    return answer;
}