#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> table(N + 1, vector<int>(N + 1,0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int input;
			cin >> input;
			table[i][j] = input + table[i-1][j]+table[i][j-1]-table[i-1][j-1];
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << table[x2][y2] - table[x2][y1-1] - table[x1-1][y2] + table[x1-1][y1-1] << "\n";
	}
}