#include<iostream>
#include<vector>
using namespace std;

#define INF 1e8

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cities(n+1, vector<int>(n+1,INF));
	for (int i = 0; i < m; i++)
	{
		int start,des,cost;
		cin >> start >> des >> cost;
		cities[start][des] = min(cost,cities[start][des]);
	}
	for (int i = 1; i <= n; i++)
	{
		cities[i][i] = 0;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cities[i][j] = min(cities[i][j], cities[i][k] + cities[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			
			if (cities[i][j] == INF)
				cout << 0 << " ";
			else
				cout << cities[i][j] << " ";
		}
		cout << "\n";
	}
}