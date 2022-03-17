#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> dp(N+1, vector<int>(11,0));
	int ret = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int size = 2; size <= N; size++)
	{
		dp[size][0] = dp[size - 1][1];
		for (int num = 1; num < 10; num++)
		{
			dp[size][num] = (dp[size - 1][num - 1] + dp[size - 1][num + 1])%1000000000;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		ret =(ret+ dp[N][i])%1000000000;
	}
	cout << ret << endl;
}