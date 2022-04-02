#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K, ret = 0;
	cin >> N >> K;

	vector<int> coins;
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		coins.push_back(value);
	}
	for (int i = 1; i < N; i++)
	{
		ret += K % (coins[i]/coins[i-1]);
		K = K / (coins[i]/coins[i-1]);
	}
	
	cout << ret+K;
}