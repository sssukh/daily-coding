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
		//점수 순으로 sort 후 선택한 방중에 가장 낮은 점수 인 방보다 거리가 작아야 선택.(가장 점수 높은 방은 무조건 선택)

		int N,answer=1,standard_idx=0;
		cin >> N;
		vector<pair<int, int>> rooms(N, { 0,0 }); // 평점, 거리
		for (int i = 0; i < N; i++)
		{
			int score, distance;
			cin >> score >> distance;
			rooms[i].first = score;
			rooms[i].second = distance;
		}

		sort(rooms.begin(), rooms.end(), cmp);

		for (int i = 1; i < N; i++)
		{
			if (rooms[i].second < rooms[standard_idx].second)
			{
				answer++;
				standard_idx = i;
			}
		}
		cout << answer << endl;
	}
}