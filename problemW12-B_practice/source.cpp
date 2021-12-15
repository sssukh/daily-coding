#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<pair<int, int>> rooms(N, { 0,0 });
		int distance = 500001, answer=0;
		for (int i = 0; i < N; i++)
		{
			int A, B;
			cin >> A >> B;
			rooms[i].first = A;
			rooms[i].second = B;
		}
		sort(rooms.begin(), rooms.end(), cmp);
		for (int i = 0; i < N; i++)
		{
			if (rooms[i].second < distance)
			{
				answer++;
				distance = rooms[i].second;
			}
		}
		cout << answer << endl;
	}
}