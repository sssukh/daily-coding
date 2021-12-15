#include<iostream>
#include <vector>

using namespace std;

void cal(vector<vector<char>>& sq, int x_start, int y_start, int size, int& Rqty, int& Bqty)
{
	char st = sq[x_start][y_start];
	if (size == 1)
	{
		if (st == 'R')
			Rqty++;
		else
			Bqty++;
		return;
	}
	for (int i = x_start; i < x_start + size; i++)
	{
		for (int j = y_start; j < y_start + size; j++)
		{
			if (st != sq[i][j])
			{
				cal(sq, x_start, y_start, size / 2, Rqty, Bqty);
				cal(sq, x_start + size / 2, y_start, size / 2, Rqty, Bqty);
				cal(sq, x_start, y_start + size / 2, size / 2, Rqty, Bqty);
				cal(sq, x_start + size / 2, y_start + size / 2, size / 2, Rqty, Bqty);
				return;
			}
		}
	}
	if (st == 'R')
		Rqty++;
	else
		Bqty++;
	return;
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		vector <vector<char>> sq(N, vector<char>(N,'\0'));
		int Rsize = 0;
		int Bsize = 0;
		int Rqty = 0;
		int Bqty = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				char color;
				cin >> color;
				sq[i][j] = color;
				if (color == 'R')
					Rsize++;
				else
					Bsize++;
			}
		}

		cal(sq, 0, 0, N, Rqty, Bqty);
		cout << Rqty << " " << Rsize << " " << Bqty << " " << Bsize << endl;
	}
}