#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int reverse(int roomno)
{
	int one = roomno / 1000;
	int ten = roomno % 1000 / 100;
	int hundred = roomno % 100 / 10;
	int thousand = roomno % 10;
	return thousand * 1000 + hundred * 100 + ten * 10 + one;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int start, escape, answer=0;
		cin >> start >> escape;
		vector<int> rooms(10000, -1);
		queue<pair<int,int>> q;
		q.push(make_pair(start,0));
		while (!q.empty())
		{
			int roomno = q.front().first;
			int min = q.front().second;
			q.pop();
			if (roomno>=0&&roomno<10000&&rooms[roomno] == -1)
			{
				rooms[roomno] = min;
				if (roomno == escape)
				{
					answer = min;
					break;
				}
				q.push(make_pair(roomno + 1, min + 1));
				q.push(make_pair(roomno - 1, min + 1));
				q.push(make_pair(reverse(roomno), min + 1));

			}
		}
		cout << answer << endl;
	}
}