#include <string>
#include <vector>
#include <unordered_map>
#include<iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;

    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    
    for (int i = 0; i < results.size(); i++)
    {
        graph[results[i][0]][results[i][1]] = 1;
        graph[results[i][1]][results[i][0]] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == 1)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (graph[i][k] == -1)
                        graph[j][k] = -1;
                }
            }
            else if (graph[i][j] == -1)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (graph[i][k] == 1)
                        graph[j][k] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j])
                cnt++;
        }
        if (cnt == n - 1)
        {
            answer++;
            cout << i << endl;
        }
    }

    return answer;
}