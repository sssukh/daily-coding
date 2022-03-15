#include<iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int,int>> stairs;
	stairs.push_back({ 0,0 });
	for (int i = 1; i <= N; i++)
	{
		int score;
		cin >> score;
		stairs.push_back({ score,score });
	}
	for (int i = 2; i <= N; i++)
	{
		stairs[i].first += max(stairs[i - 2].first, stairs[i - 2].second);
		stairs[i].second += stairs[i - 1].first;
	}

	cout << max(stairs.back().first, stairs.back().second) << endl;
}