#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct info
{
	int x, y, time=0;
};

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int length;
		cin >> length;
		vector<vector<bool>> board(length, vector<bool>(length, 0));
		queue<info> q;
		info source, destination;
		cin >> source.x >> source.y >> destination.x >> destination.y;
		q.push(source);
		while (!q.empty())
		{
			info crt = q.front();
			q.pop();
			if (crt.x == destination.x && crt.y == destination.y)
			{
				cout << crt.time << "\n";
				break;
			}
			if (crt.x >= 0 && crt.x < length && crt.y >= 0 && crt.y < length &&
				!board[crt.x][crt.y])
			{
				board[crt.x][crt.y] = 1;
				q.push({ crt.x + 2,crt.y + 1,crt.time + 1 });
				q.push({ crt.x + 2,crt.y - 1,crt.time + 1 });
				q.push({ crt.x - 2,crt.y + 1,crt.time + 1 });
				q.push({ crt.x - 2,crt.y + 1,crt.time + 1 });
				q.push({ crt.x + 1,crt.y + 2,crt.time + 1 });
				q.push({ crt.x - 1,crt.y + 2,crt.time + 1 });
				q.push({ crt.x + 1,crt.y - 2,crt.time + 1 });
				q.push({ crt.x - 1,crt.y - 2,crt.time + 1 });
			}
		}
	}
}