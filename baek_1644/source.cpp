#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int N, left = 0, right = 0, total = 0,ret=0;
	cin >> N;
	vector<bool> isPrime(N+1,1);
	vector<int> primes;
	/*
	for (int i = 2; i <= N; i++)
	{
		int j;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > sqrt(i))
			primes.push_back(i);
	}
	*/

	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
			for (int j = 2 * i; j <= N; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}
	if(!primes.empty())
		total = primes.front();
	while (left <= right)
	{
		if (total == N)
		{
			++ret;
			++right;
			if (right >= primes.size())
				break;
			total += primes[right];
		}
		else if (total < N)
		{
			++right;
			if (right >= primes.size())
				break;
			total += primes[right];
		}
		else
		{
			total -= primes[left];
			++left;
		}
	}
	cout << ret;
}