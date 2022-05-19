#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

#define INF 1e9

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int main()
{
	int V, E,K;
	cin >> V >> E >> K;
	vector<vector<pair<int,int>>> nodeAdjacent(V+1, vector<pair<int,int>>());
	vector<int> distances(V + 1,INF);
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> fringe;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		nodeAdjacent[u].push_back({ v,w });
	}
	fringe.push({ K,0 });
	do
	{
		pair<int, int> crt = fringe.top();
		fringe.pop();
		if (distances[crt.first] > crt.second)
		{
			distances[crt.first] = crt.second;
			for (int i = 0; i < nodeAdjacent[crt.first].size(); i++)
			{
				pair<int, int> tmp = nodeAdjacent[crt.first][i];
				fringe.push({ tmp.first,tmp.second + crt.second });
			}
		}
	} while (!fringe.empty());
	for (int i = 1; i <= V; i++)
	{
		if (distances[i] == INF)
			cout << "INF" << "\n";
		else
			cout << distances[i] << "\n";
	}
}