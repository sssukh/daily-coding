#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct cmp
{
	bool operator() (int a, int b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
		{
			pq.push(x);
		}
	}
}