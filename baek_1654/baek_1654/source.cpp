#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int K, N, ret;
	long long mid,len_lo, len_hi = 0x7FFFFFFF;
	cin >> K >> N;
	vector<int> lan(K);
	for (int i = 0; i < K; i++)
	{
		int len;
		cin >> len;
		lan[i] = len;
		if (len > len_hi)
			len_hi = len;
	}
	len_lo = 0;
	while (len_lo<=len_hi)
	{
		mid = (len_lo + len_hi) / 2;
		if (mid == 0)
		{
			ret = 1;
			break;
		}
		long long count = 0;
		for (int i = 0; i < K; i++)
		{
			count += lan[i] / mid;
		}
		if (count < N)
		{
			len_hi = mid - 1;
		}
		else
		{
			len_lo = mid + 1;
			ret = mid;
		}
	}
	cout << ret;

}