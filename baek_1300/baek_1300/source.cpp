#include<iostream>
#include<vector>
using namespace std;

int main()
{
	long long N, k;
	cin >> N >> k;
	long long mid, lo = 1, hi = N * N;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		long long count = 0,qty=0;
		for (int i = 1; i <= min(N,mid); i++)
		{
			long long j = mid / i;
			count += min(j, N);
			if (mid % i == 0&&j<=N)
			{
				++qty;
			}
		}
		//cout << "count - qty : " << count - qty << " count : " << count <<" mid : "<<mid<<endl;
		if (count - qty < k && k <= count)
		{
			// mid°¡ Á¤´ä
			break;
		}
		else if (k <= count - qty)
		{
			hi = mid - 1;
		}
		else if (k > count)
		{
			lo = mid + 1;
		}
	}
	cout << mid;

}