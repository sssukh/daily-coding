#include<iostream>
#include<queue>
#include<vector>
using namespace std;



int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> pos(100001, 100002);
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	while (!q.empty())
	{
		pair<int, int> crt = q.front(); int tmp = crt.first;
		q.pop();
		if (crt.first >= 0 && crt.first <= 100000)
		{
			if (crt.first % 2 == 0)
			{
				pos[crt.first] = min(pos[crt.first], pos[crt.first / 2]);
			}
			pos[crt.first] = min(pos[crt.first], crt.second);
			if(crt.first+1<=100000&&pos[crt.first+1]> pos[crt.first] + 1)
				q.push({ crt.first + 1,pos[crt.first] + 1 });
			if (crt.first-1>=0&&pos[crt.first - 1] > pos[crt.first] + 1)
				q.push({ crt.first - 1,pos[crt.first] + 1 });
		}
	}
	cout << pos[K];
}