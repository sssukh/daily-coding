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
		//���� ������ sort �� ������ ���߿� ���� ���� ���� �� �溸�� �Ÿ��� �۾ƾ� ����.(���� ���� ���� ���� ������ ����)

		int N,answer=1,standard_idx=0;
		cin >> N;
		vector<pair<int, int>> rooms(N, { 0,0 }); // ����, �Ÿ�
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