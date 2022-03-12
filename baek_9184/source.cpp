#include <iostream>
#include <vector>
using namespace std;




int main()
{
	vector<vector<vector<int>>> map(21,vector<vector<int>>(21,vector<int>(21)));

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int k = 0; k <= 20; k++)
			{
				if (i <= 0 || j <= 0 || k <= 0)
					map[i][j][k] = 1;
				else if(i>20||j>20||k>20)
				{
					map[i][j][k] = map[20][20][20];
				}
				else if (i < j && j < k)
				{
					map[i][j][k] = map[i][j][k - 1] + map[i][j - 1][k - 1] - map[i][j - 1][k];
				}
				else
				{
					map[i][j][k] = map[i - 1][j][k] + map[i - 1][j - 1][k] + map[i - 1][j] [k - 1] - map[i - 1][j - 1][k - 1];
				}
			}
		}
	}

	int a, b, c;
	cin >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1)
	{
		int print;
		if (a <= 0 || b <= 0 || c <= 0)
			print = 1;
		else if (a > 20 || b > 20 || c > 20)
			print = map[20][20][20];
		else
			print = map[a][b][c];
		cout << "w(" << a << ", " << b << ", " << c << ") = " << print << endl;
		cin >> a >> b >> c;
	}
}