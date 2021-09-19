#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;







int BFS(int, vector<vector<int>>&,int&);





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<vector<int>> town(n+1, vector<int>(n+1,0));
		int max = 0;
		
		for (int i = 0; i < n - 1; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			town[u][v] = d;
			town[v][u] = d;
		}
		
		BFS(BFS(1, town, max), town, max);

		cout << max-1 << "\n";
	}

}




int BFS(int start, vector<vector<int>>& town,int& max)
{
	vector<int> visited(town.size(), 0);
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	int idx =0;
	while (!q.empty())
	{
		int search = q.front();
		q.pop();
		for (int i = 1; i < town.size(); i++)
		{
			if (town[search][i] > 0 && visited[i] ==0)
			{
				visited[i] += town[search][i]+visited[search];
				q.push(i);
				if (max < visited[i])
				{
					max = visited[i];
					idx = i;
				}

			}
		}
	}
	return idx;
}
