#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> dp(1,0);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A[i] = num;
	}
	for (int i = 0; i < N; i++)
	{
		if (dp.back() < A[i])
		{
			dp.push_back(A[i]);
		}
		else
		{
			int mid,lo = 0, hi = dp.size() - 1;
			while (lo <= hi)
			{
				mid = (lo + hi) / 2;
				if (dp[mid] == A[i])
					break;
				else if (dp[mid] < A[i])
				{
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}
			if (dp[mid] < A[i])
				++mid;
			dp[mid] = A[i];
		}
	}
	cout << dp.size()-1;
}