#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	int N,end_time,ret=1;
	cin >> N;
	vector<pair<int, int>> conferences(N);
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		conferences[i] = { start,end };
	}
	sort(conferences.begin(), conferences.end(), cmp);
	end_time = conferences.front().second;
	for (int i = 1; i < N; i++)
	{
		if (end_time <= conferences[i].first)
		{
			end_time=conferences[i].second;
			++ret;
		}
	}
	cout << ret;
}