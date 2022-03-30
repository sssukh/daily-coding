#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int DP(vector<vector<int>>& dp,string& str1,string& str2, int idx1, int idx2)
{
	if (idx1 == str1.size() || idx2 == str2.size())
		return 0;
	if (dp[idx1][idx2] == -1)
	{
		if (str1[idx1] == str2[idx2])
		{
			return dp[idx1][idx2] = 1 + DP(dp, str1, str2, idx1 + 1, idx2 + 1);
		}
		else
		{
			return dp[idx1][idx2] = max(DP(dp, str1, str2, idx1 + 1, idx2), DP(dp, str1, str2, idx1, idx2 + 1));
		}
	}
	else
		return dp[idx1][idx2];
}

int main()
{
	// 2  1,3 6 2 1,3 5
	
	/*
	string input1, input2;
	cin >> input1 >> input2;
	vector<vector<pair<int,int>>> lcs(input2.size());
	
	for (int i=0;i<input2.size();i++)
	{
		for (int j=0;j<input1.size();j++)
		{
			if(input2[i]==input1[j])
				lcs[i].push_back({ j,0 });
		}
	}
	
	for (int i = 0; i < input2.size(); i++)
	{
		for (int i_idx = 0; i_idx < lcs[i].size(); i_idx++)
		{
			int maxlen = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				for (int j_idx = 0; j_idx < lcs[j].size(); j_idx++)
				{
					if (lcs[i][i_idx].first > lcs[j][j_idx].first)
					{
						maxlen = max(maxlen, lcs[j][j_idx].second);
					}
				}
			}
			lcs[i][i_idx].second = maxlen + 1;
			ret = max(ret, lcs[i][i_idx].second);
		}
	}
	*/

	string input1, input2;
	cin >> input1 >> input2;
	vector<vector<int>> dp(input1.size()+1, vector<int>(input2.size()+1,0));
	int ret = 0;
	for (int i = 1; i <= input1.size(); i++)
	{
		for (int j = 1; j <= input2.size(); j++)
		{
			if (input1[i-1] == input2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			ret = max(ret, dp[i][j]);
			cout << dp[i][j] << "\t";
		}
		cout << "\n\n";
	}

	cout << ret;
}