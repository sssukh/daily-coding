#include<iostream>
#include<vector>
using namespace std;
#define INF 1000000000
#define NEGATIVE_INF -1000000000

int seq[11];
int oper[4]; // + , - , * , /
int mx = NEGATIVE_INF, mn = INF;

void put_oper(int oper_pos, int N, int current=seq[0])
{
	if (oper_pos == N - 1)
	{
		mx = max(mx, current);
		mn = min(mn, current);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{
			--oper[i];
			if (i == 0)
			{
				put_oper(oper_pos + 1, N, current + seq[oper_pos + 1]);
			}
			else if (i == 1)
			{
				put_oper(oper_pos + 1, N, current - seq[oper_pos + 1]);
			}
			else if (i == 2)
			{
				put_oper(oper_pos + 1, N, current * seq[oper_pos + 1]);
			}
			else
			{
				put_oper(oper_pos + 1, N, current / seq[oper_pos + 1]);
			}
			++oper[i];
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		seq[i] = num;
	}
	for (int i = 0; i < 4; i++)
	{
		int qty;
		cin >> qty;
		oper[i] = qty;
	}
	put_oper(0, N);
	cout << mx << " " << mn;
}