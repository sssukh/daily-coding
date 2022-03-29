#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//8 2 9 1 - 4 6 - 7 10
	//4 2 - 6 - 7 9 1 3 10
	int n;
	cin >> n;
	vector<int> wires(501,0);
	vector<int> dp(501,0);
	int longest = 0;
	for (int i = 0; i < n; i++)
	{
		int from, to;
		cin >> from >> to;
		wires[from] = to;
	}
	for (int i = 0; i < 500; i++)
	{
		if (wires[i] == 0)
			continue;
		int maxlen = 0;
		for (int j = 0; j < i; j++)
		{
			if (wires[j]!=0&&wires[i] > wires[j])
				maxlen = max(maxlen, dp[j]);
		}
		dp[i] = maxlen + 1;
		longest = max(longest, dp[i]);
	}
	cout <<  n - longest;
}