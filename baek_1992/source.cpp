#include<iostream>
using namespace std;

string video[64];
string ret;

void Compress(int row, int col, int len)
{
	if (len == 1)
	{
		ret += video[row][col];
		return;
	}
	char comp = video[row][col];
	for (int i = row; i < row + len; i++)
	{
		for (int j = col; j < col + len; j++)
		{
			if (comp != video[i][j])
			{
				ret += '(';
				Compress(row, col, len / 2);
				Compress(row, col + len / 2, len / 2);
				Compress(row + len / 2, col, len / 2);
				Compress(row + len / 2, col + len / 2, len / 2);
				ret += ')';
				return;
			}
		}
	}
	ret += video[row][col];
	return;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
			string input;
			cin >> input;
			video[i] = input;
	}
	Compress(0, 0, N);
	cout << ret;
}