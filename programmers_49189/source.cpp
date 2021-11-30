#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    vector < vector < bool >> graph(n+1, vector<bool>(n+1, 0));
    vector<int> visited(n+1, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]][edge[i][1]] = 1;
        graph[edge[i][1]][edge[i][0]] = 1;
    }
    q.push(make_pair(1, 0));
    while (!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (visited[i]==0 && graph[node][i])
            {
                q.push(make_pair(i, dis + 1));
                visited[i] = dis + 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (max < visited[i])
        {
            max = visited[i];
            answer = 1;
        }
        else if (max == visited[i])
            answer++;
    }

    return answer;
}