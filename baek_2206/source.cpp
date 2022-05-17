#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1e8

typedef struct info
{
	int x, y, time = 0;
	bool brokedown = 0;
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> map(N);
	vector<vector<pair<int, int>>> dis(N, vector<pair<int, int>>(M, { MAX,MAX }));
	queue<info> q; q.push({ 0,0,1,0 });
	for (int i = 0; i < N; i++)
	{
			string input;
			cin >> input;
			map[i] = input;
	}

	while (!q.empty())
	{
		info crt = q.front();
		q.pop();

		if (crt.x >= 0 && crt.x < N &&
			crt.y >= 0 && crt.y < M )
		{
			if (map[crt.x][crt.y] == '1' && !crt.brokedown &&
				dis[crt.x][crt.y].second > crt.time)
			{
				dis[crt.x][crt.y].second = crt.time;
				q.push({ crt.x-1,crt.y,crt.time + 1,1 });
				q.push({ crt.x+1,crt.y,crt.time + 1,1 });
				q.push({ crt.x,crt.y+1,crt.time + 1,1 });
				q.push({ crt.x,crt.y-1,crt.time + 1,1 });
			}
			else if (map[crt.x][crt.y] == '0')
			{
				if (crt.brokedown&&crt.time<dis[crt.x][crt.y].second)
				{
					dis[crt.x][crt.y].second = crt.time;
					q.push({ crt.x - 1,crt.y,crt.time + 1,crt.brokedown });
					q.push({ crt.x + 1,crt.y,crt.time + 1,crt.brokedown });
					q.push({ crt.x,crt.y + 1,crt.time + 1,crt.brokedown });
					q.push({ crt.x,crt.y - 1,crt.time + 1,crt.brokedown });
				}
				else if (!crt.brokedown && crt.time < dis[crt.x][crt.y].first)
				{
					dis[crt.x][crt.y].first = crt.time;
					q.push({ crt.x - 1,crt.y,crt.time + 1,crt.brokedown });
					q.push({ crt.x + 1,crt.y,crt.time + 1,crt.brokedown });
					q.push({ crt.x,crt.y + 1,crt.time + 1,crt.brokedown });
					q.push({ crt.x,crt.y - 1,crt.time + 1,crt.brokedown });
				}
			}
		}
	}


	
	if (dis[N - 1][M - 1].first == MAX && dis[N - 1][M - 1].second == MAX)
		cout << -1;
	else
		cout << min(dis[N - 1][M - 1].first, dis[N - 1][M - 1].second);
}