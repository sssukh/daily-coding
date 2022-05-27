#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 1e8

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

vector<int> dijkstra(int s, vector<vector<pair<int,int>>>& routes)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<int> ret(routes.size(),INF);
	pq.push({ s, 0 });
	while (!pq.empty())
	{
		pair<int, int> crt = pq.top();
		pq.pop();
		if (ret[crt.first] > crt.second)
		{
			ret[crt.first] = crt.second;
			for (int i = 0; i < routes[crt.first].size(); i++)
			{
				pq.push({ routes[crt.first][i].first,routes[crt.first][i].second + crt.second });
			}
		}
	}
	return ret;
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, t,s,g,h;
		cin >> n >> m >> t>>s>>g>>h;
		vector<vector<pair<int,int>>> routes(n+1);
		vector<bool> target(n+1,0);
		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			routes[a].push_back({ b,d });
			routes[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			target[x] = true;
		}
		vector<int> fromS = dijkstra(s, routes);
		vector<int> fromG = dijkstra(g, routes);
		vector<int> fromH = dijkstra(h, routes);
		for (int i = 1; i <= n; i++)
		{
			if (target[i]&&fromS[i]==min(fromS[g]+fromG[h]+fromH[i],fromS[h]+fromH[g]+fromG[i]))
			{
				cout << i << " ";
			}
		}
	}
}