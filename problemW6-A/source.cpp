#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
			return a.second > b.second;
		else
			return a.first > b.first;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	queue<pair<int, int>> customer;	// time, price
	priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> counter;  // time, index
	int total_time=0;
	vector<int> answer(N,0);

	for (int i = 0; i < M; i++)
	{
		int time, price;
		cin >> time >> price;
		customer.push(make_pair(time, price));
	}
	int idx = 0;
	while (!customer.empty())
	{
		int time = customer.front().first;
		int price = customer.front().second;
		customer.pop();
		if (counter.size() < N) 
		{
			counter.push(make_pair(time, idx));
			answer[idx] += price;
			idx++;
			if (time > total_time)
				total_time = time;
		}
		else
		{
			int tmp_time = counter.top().first + time;
			int tmp_idx = counter.top().second;
			counter.pop();
			answer[tmp_idx] += price;
			counter.push(make_pair(tmp_time, tmp_idx));
			if (tmp_time > total_time)
				total_time = tmp_time;
		}
	}
	
	cout << total_time << "\n";
	for (int p : answer)
		cout << p << "\n";


}

