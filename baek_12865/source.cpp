#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> weights(N + 1);
	vector<int> values(N + 1);
	vector<vector<int>> dp(N + 1,vector<int>(K + 1 ,0)); //i번째 물건까지 봤을 때 무게가 j일 때의 가치
	vector<int> dp2(K + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int weight, value;
		cin >> weight >> value;
		weights[i] = weight;
		values[i] = value;
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= weights[i])
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weights[i]] + values[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = K; j > 0; j--)
		{
			if (j - weights[i] >= 0)
				dp2[j] = max(dp2[j - weights[i]] + values[i], dp2[j]);
			
		}
	}

	cout << dp2[K];
}