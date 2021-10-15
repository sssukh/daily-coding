#include<iostream>
#include<queue>
using namespace std;

struct pos
{
	int x, y;
};

struct cmp
{
	bool operator()(pos a, pos b)
	{
		if (a.x * a.x + a.y * a.y == b.x * b.x + b.y * b.y)
		{
			if (a.x == b.x)
				return a.y > b.y;
			else
				return a.x > b.x;
		}
		else
			return a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y ? true:false;
	}
};
struct cmp2
{
	bool operator()(pos a, pos b)
	{
		if (a.x * a.x + a.y * a.y == b.x * b.x + b.y * b.y)
		{
			if (a.x == b.x)
				return a.y < b.y;
			else
				return a.x < b.x;
		}
		else
			return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y ? true : false;
	}
};

bool R_is_smaller(pos a, pos b)
{
	if (a.x * a.x + a.y * a.y == b.x * b.x + b.y * b.y)
	{
		if (a.x == b.x)
			return a.y > b.y;
		else
			return a.x > b.x;
	}
	else
		return a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y ? true : false;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;
		pos tmp;
		priority_queue<pos, vector<pos>, cmp> burgers;
		priority_queue<pos, vector<pos>, cmp2> Kth_burgers;
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			burgers.push(pos{ x,y });
		}
		for (int i = 0; i < K; i++)
		{
			Kth_burgers.push(burgers.top());
			burgers.pop();
		}
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			burgers.push(pos{ x,y });

			if (R_is_smaller(Kth_burgers.top(),burgers.top()))
			{
				Kth_burgers.push(burgers.top());
				burgers.pop();
				Kth_burgers.pop();
			}
			tmp = Kth_burgers.top();
			cout << tmp.x << " " << tmp.y << "\n";
		}
	}
	
}

