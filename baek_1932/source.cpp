#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> tri(N, vector<int>());
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int num;
			cin >> num;
			tri[i].push_back(num);
		}
	}
	for (int row = N - 2; row >= 0; row--)
	{
		for (int col = 0; col < tri[row].size(); col++)
		{
			tri[row][col] += max(tri[row + 1][col], tri[row + 1][col + 1]);
		}
	}
	cout << tri[0][0] << endl;
}