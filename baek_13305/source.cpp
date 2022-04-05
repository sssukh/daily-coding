#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long current_cost,ret=0;
	vector<long long> distances;
	vector<long long> costs;
	for (int i = 0; i < N - 1; i++)
	{
		long long dis;
		cin >> dis;
		distances.push_back(dis);
	}
	for (int i = 0; i < N; i++)
	{
		long long cost;
		cin >> cost;
		costs.push_back(cost);
	}
	current_cost = costs.front();
	for (int i = 0; i < N - 1; i++)
	{
		ret+=current_cost* distances[i];
		current_cost = min(current_cost, costs[i + 1]);
	}
	cout << ret;
}