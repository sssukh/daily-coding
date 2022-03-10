#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(vector<vector<bool>>& graph, int idx,vector<bool>& visited)
{
	if (visited[idx])
		return;
	cout << idx << " ";
	visited[idx] = 1;
	for (int i = 0; i < graph[idx].size(); i++)
	{
		if (graph[idx][i])
			DFS(graph, i, visited);
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	vector<bool> DFS_visited(N + 1, 0);
	vector<bool> BFS_visited(N + 1, 0);
	vector<vector<bool>> graph(N + 1, vector < bool > (N + 1, 0));
	queue<int> q;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	DFS(graph, V,DFS_visited);
	cout << endl;
	q.push(V);
	while (!q.empty())
	{
		int tmp = q.front(); q.pop();
		if (BFS_visited[tmp])
			continue;
		cout << tmp << " ";
		BFS_visited[tmp] = 1;
		for (int i = 0; i < graph[tmp].size(); i++)
		{
			if (graph[tmp][i])
				q.push(i);
		}
	}
}