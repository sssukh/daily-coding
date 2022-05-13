#include<iostream>
#include<vector>
using namespace std;


int dfs(vector<vector<int>>& comp, vector<bool>& visited, int idx)
{
	if (visited[idx])
		return 0;
	int ret = 1;
	visited[idx] = true;
	for (int i = 0; i < comp[idx].size(); i++)
	{
		ret += dfs(comp, visited, comp[idx][i]);
	}
	return ret;
}


int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> comp(N+1, vector<int>());
	vector<bool> visited(N+1,0);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		comp[a].push_back(b);
		comp[b].push_back(a);
	}
	cout << dfs(comp, visited, 1)-1;
}