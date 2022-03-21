#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[1000];
	vector<int> dp(N,1);	
	int ret = 1;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
	}
	for (int i = 1; i < N; i++)
	{
		int tmp;
		int mx = 0;
		for (tmp = i - 1; tmp >= 0; tmp--)
		{
			if (arr[i] > arr[tmp] && mx < dp[tmp])
				mx = dp[tmp];
		}
			dp[i] = mx + 1;
		ret = max(ret, dp[i]);
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << dp[i]<< "\t";
	}
	cout << endl;
	
	cout << ret << endl;
}