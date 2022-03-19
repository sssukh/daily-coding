#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> wines(n + 1);
	vector<pair<int, int>> dp(n + 1, { 0,0 });	//total, continuous add
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int wine;
		cin >> wine;
		wines[i] = wine;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i].first = dp[i - 1].second + wines[i];
		dp[i].second = wines[i];
		for (int j = 2; j <= 3&&i-j>=0; j++)
		{
			
			dp[i].second = max(dp[i].second, max(dp[i - j].first, dp[i - j].second) + wines[i]);
		}
		ret = max(ret, max(dp[i].first, dp[i].second));
	}
	
	/*
	for (int i =0;i<=n;i++)
	{
		cout << dp[i].first << "\t";
	}
	cout << "\n";
	for (int i = 0; i <= n; i++)
	{
		cout << dp[i].second << "\t";
	}
	*/
	cout << ret << endl;
	
	

}