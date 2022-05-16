#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1e8

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> board(101, -1);
	vector<int> cnt(101, MAX);
	queue<pair<int,int>> q;  //position, time
	q.push({ 1, 0 });
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		board[u] = v;
	}

	while (!q.empty())
	{
		int pos = q.front().first, time = q.front().second;
		q.pop();

		
		if (pos <= 100)
		{
			while (board[pos] != -1)
			{
				pos = board[pos];
			}
			if (cnt[pos] > time)
			{
				cnt[pos] = time;
				q.push({ pos + 1,time + 1 });
				q.push({ pos + 2,time + 1 });
				q.push({ pos + 3,time + 1 });
				q.push({ pos + 4,time + 1 });
				q.push({ pos + 5,time + 1 });
				q.push({ pos + 6,time + 1 });
			}
		}
	}
	cout << cnt[100];
}