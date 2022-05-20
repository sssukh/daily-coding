#include<iostream>
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

void dijkstra(vector<vector<pair<int,int>>>& graph, int start, vector<int>& distance)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq; // 노드, 거리
	pq.push({ start,0 });
	while (!pq.empty())
	{
		//cout << start << " " << destination << endl;
		pair<int, int> crt = pq.top();
		pq.pop();
		//cout << "crt : " << crt.first << " " << crt.second << endl;
		if (distance[crt.first] > crt.second)
		{
			distance[crt.first] = crt.second;
			for (int i = 0; i < graph[crt.first].size(); i++)
			{
				pair<int, int> tmp = graph[crt.first][i];
				pq.push({ tmp.first,tmp.second + crt.second });
			}
		}
	}
}


int main()
{
	int N, E, v1, v2;
	long long ret1,ret2;
	cin >> N >> E;
	vector<vector<pair<int,int>>> graph(N + 1, vector<pair<int,int>>());
	vector<int> fromS(N+1,INF);
	vector<int> fromV1(N+1,INF);
	vector<int> fromV2(N+1,INF);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	dijkstra(graph, 1, fromS);
	dijkstra(graph, v1, fromV1);
	dijkstra(graph, v2, fromV2);
	// 구해야할 것. from 1 to v1, from 1 to v2, v1 to v2, v1 to N, v2 to N
	// 비교해야할 것. from 1 to v1 to v2 to N, from 1 to v2 to v1 to N
	
	

	if ((fromS[v1] == INF && fromS[v2] == INF)||(fromV1[N]==INF&&fromV2[N]==INF)||
		fromV1[v2]==INF)
	{
		cout << -1;
	}
	else
	{
		ret1 = (long long)fromS[v1] + fromV1[v2] + fromV2[N];
		ret2 = (long long)fromS[v2] + fromV2[v1] + fromV1[N];
		cout << min(ret1, ret2);
	}
	

}