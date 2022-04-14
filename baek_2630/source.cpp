#include<iostream>
#include<vector>
using namespace std;

int paper[128][128];
int white, blue;

void cutPaper(int row, int col, int length)
{
	if (length == 1)
	{
		if (paper[row][col])
			++blue;
		else
			++white;
		return;
	}
	bool current_color = paper[row][col];
	for (int i = row; i < row + length; i++)
	{
		for (int j = col; j < col + length; j++)
		{
			if (current_color != paper[i][j])
			{
				cutPaper(row, col, length / 2);
				cutPaper(row + length / 2, col, length / 2);
				cutPaper(row, col + length / 2, length / 2);
				cutPaper(row + length / 2, col + length / 2, length / 2);
				return;
			}
		}
	}
	if (current_color)
		++blue;
	else
		++white;
	return;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			paper[i][j] = input;
		}
	}
	cutPaper(0, 0, N);
	cout << white << "\n" << blue;
}