#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1e8

typedef struct tomato
{
	int x, y, z, time = 0;
};

int main()
{
	int N, M, H,ret=0;
	cin >> M >> N >> H;
	vector<vector<vector<int>>> box(N, vector<vector<int>>(M, vector<int>(H)));
	vector<vector<vector<int>>> timeBoard(N, vector<vector<int>>(M, vector<int>(H,MAX)));
	queue<tomato> q;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int input;
				cin >> input;
				box[i][j][k] = input;
				if (input)
				{
					timeBoard[i][j][k] = input;
					if (input == 1)
					{
						q.push({ i,j,k,0 });
					}
				}

			}
		}
	}
	while (!q.empty())
	{
		tomato crt = q.front();
		q.pop();

		if (crt.x >= 0 && crt.x < N &&
			crt.y >= 0 && crt.y < M &&
			crt.z >= 0 && crt.z < H &&
			box[crt.x][crt.y][crt.z] >= 0 &&
			timeBoard[crt.x][crt.y][crt.z]>crt.time)
		{
			timeBoard[crt.x][crt.y][crt.z] = crt.time;
			q.push({ crt.x + 1,crt.y,crt.z,crt.time + 1 });
			q.push({ crt.x - 1,crt.y,crt.z,crt.time + 1 });
			q.push({ crt.x,crt.y + 1,crt.z,crt.time + 1 });
			q.push({ crt.x,crt.y - 1,crt.z,crt.time + 1 });
			q.push({ crt.x,crt.y,crt.z + 1,crt.time + 1 });
			q.push({ crt.x,crt.y,crt.z - 1,crt.time + 1 });
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < H; k++)
			{
				if (timeBoard[i][j][k] == MAX)
				{
					cout << -1;
					return 0;
				}
				ret = max(ret, timeBoard[i][j][k]);
			}
		}
	}
	cout<<ret;
}