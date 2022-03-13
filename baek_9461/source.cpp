#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long> dp(101);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << dp[N] << endl;
	}
}