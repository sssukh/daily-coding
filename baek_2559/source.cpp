#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, K, currentSum = 0, mx = -1e9;
	cin >> N >> K;
	vector<int> tem(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int temperature;
		cin >> temperature;
		tem[i] = temperature;
		currentSum += temperature;
		if (i >= K)
		{
			currentSum -= tem[i - K];
			mx = max(mx, currentSum);
		}
	}
	cout << mx;
}