#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1e8
typedef struct toma
{
	int row, col, time=0;
};

int main()
{
	int N, M,ret=0;
	cin >> M >> N;
	vector<vector<int>> box(N, vector<int>(M));
	vector<vector<int>> timeBoard(N, vector<int>(M,MAX));
	queue<toma> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tomato;
			cin >> tomato;
			box[i][j] = tomato;
			if (tomato)
			{
				timeBoard[i][j] = tomato;
				if(tomato==1)
				 q.push({ i,j,0 });
			}
		}
	}
	
	while (!q.empty())
	{
		toma crt = q.front();
		q.pop();

		if (crt.row >= 0 && crt.row < N &&
			crt.col >= 0 && crt.col < M &&
			box[crt.row][crt.col] >= 0 &&
			timeBoard[crt.row][crt.col] > crt.time)
		{
			//cout << crt.row << " " << crt.col << endl;
			timeBoard[crt.row][crt.col] = crt.time;
			q.push({ crt.row + 1,crt.col,crt.time + 1 });
			q.push({ crt.row - 1,crt.col,crt.time + 1 });
			q.push({ crt.row,crt.col + 1,crt.time + 1 });
			q.push({ crt.row,crt.col - 1,crt.time + 1 });
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (timeBoard[i][j] == MAX)
			{
				cout << -1 << "\n";
				return 0;
			}
			ret = max(ret, timeBoard[i][j]);
		}
	}
	cout << ret;
}