#include<iostream>
using namespace std;

#define MAX 2187

int N, paper[MAX][MAX], pos_one = 0, zeros = 0, neg_one = 0;

void checkPaper(int startRow, int startCol, int length)
{
	int current = paper[startRow][startCol];
	if (length == 1)
	{
		if (current == 1)
		{
			++pos_one;
		}
		else if (current == -1)
		{
			++neg_one;
		}
		else
		{
			++zeros;
		}
		return;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (paper[startRow + i][startCol + j] != current)
			{
				for (int row = 0; row < 3; row++)
				{
					for (int col = 0; col < 3; col++)
					{
						checkPaper(startRow + row * (length / 3), startCol + col * (length / 3), length / 3);
					}
				}
				return;
			}
		}
	}
	if (current == 1)
	{
		++pos_one;
	}
	else if (current == -1)
	{
		++neg_one;
	}
	else
	{
		++zeros;
	}
	return;
}

int main()
{
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
	checkPaper(0, 0, N);
	cout << neg_one << " " << zeros << " " << pos_one;
}