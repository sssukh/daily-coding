#include<iostream>
#include<vector>
using namespace std;

#define INF 987654321
int main()
{
	int N, M;
	cin >> N >> M;
	bool canGoBack = false;
	vector<vector<int>> mat;
	vector<long long> dist(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mat.push_back({ a,b,c });
	}
	dist[1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < mat.size(); j++)
		{
			int start = mat[j][0], des = mat[j][1], weight = mat[j][2];

			if (dist[start] != INF && dist[des] > dist[start] + weight)
				dist[des] = dist[start] + weight;
		}
	}

	for (int j = 0; j < mat.size(); j++)
	{
		int start = mat[j][0], des = mat[j][1], weight = mat[j][2];

		if (dist[start] != INF && dist[des] > dist[start] + weight)
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
}