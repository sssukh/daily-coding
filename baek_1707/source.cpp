#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int K;
	cin >> K;
	while (K--)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int>> graph(V+1, vector<int>());
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		queue<pair<int, int>> q;
		vector<short> group(V + 1,0);
		bool isBipartite = true;
		for (int idx = 1; idx <= V; idx++)
		{
			if (group[idx] == 0)
			{
				q.push({ idx,1 });

				while (!q.empty())
				{
					pair<int, int> crt = q.front();
					q.pop();

					if (group[crt.first] == 0)
					{
						group[crt.first] = crt.second;
						for (int i = 0; i < graph[crt.first].size(); i++)
						{
							q.push({ graph[crt.first][i],-crt.second });
						}
					}
					else if (group[crt.first] != crt.second)
					{
						isBipartite = false;
						break;
					}
				}
			}
		}

		if (isBipartite)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	
}