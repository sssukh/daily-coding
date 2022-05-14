#include<iostream>
#include<queue>
using namespace std;

void pushQ(int lo, int hi, queue<pair<int,int>>& q, pair<int,int> push)
{
	if (push.first<lo || push.first>hi)
	{
		return;
	}
	q.push({ push });
}

int main()
{
	int N, K;
	bool pos[100001] = { 0, };
	cin >> N >> K;
	queue<pair<int,int>> q;
	
	q.push({ N,0 });
	while (!q.empty())
	{
		pair<int,int> current = q.front();
		q.pop();
		if (current.first == K)
		{
			cout << current.second << endl;
			break;
		}
		if (!pos[current.first])
		{
			pos[current.first] = 1;
			pushQ(0, 100000, q, { current.first + 1,current.second + 1 });
			pushQ(0, 100000, q, { current.first - 1,current.second + 1 });
			pushQ(0, 100000, q, { current.first * 2,current.second + 1 });
		}
	}



}