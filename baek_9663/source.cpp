#include<iostream>
#include<vector>
using namespace std;

bool check(vector<pair<int,int>>& queens, int row, int col)
{
	for (int i = 0; i < queens.size(); ++i)
	{
		if (queens[i].second == col)
			return false;
		if (row - queens[i].first == abs(col - queens[i].second))
			return false;
	}
	return true;
}

int NQ(vector<pair<int,int>>& queens,int N, int row,int count)
{
	if (count == N)
		return 1;
	if (row >= N)
		return 0;
	int ret = 0;
	for (int col = 0; col < N; ++col)
	{
		if (check(queens, row, col))
		{
			queens.push_back({ row,col });
			ret += NQ(queens,N, row + 1, count + 1);
			queens.pop_back();
		}
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> queens;
	cout << NQ(queens,N, 0, 0);
}