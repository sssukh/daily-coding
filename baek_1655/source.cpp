#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> less_max;
	priority_queue<int, vector<int>, greater<int>> greater_min;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (!greater_min.empty()&&num > greater_min.top())
		{
			less_max.push(greater_min.top());
			greater_min.pop();
			greater_min.push(num);
		}
		else
			less_max.push(num);

		if (i % 2)
		{
			greater_min.push(less_max.top());
			less_max.pop();
		}
		
		cout <<less_max.top() << "\n";
	}
}