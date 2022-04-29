#include<iostream>
using namespace std;
#define MOD 1000000007

long long powNum(long long num, int pow)
{
	if (pow == 1)
	{
		return num % MOD;
	}
	if (pow % 2 > 0)
	{
		return (powNum(num, pow - 1) * num)% MOD;
	}
	else
	{
		long long current = powNum(num, pow / 2);
		return (current*current) % MOD;
	}
}

int main()
{
	int N, K;
	long long  Kfactorial=1, N_Kfactorial=1, current=1;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		current = (current * i) % MOD;
		if (i == K)
			Kfactorial = current;
		if (i == N - K)
			N_Kfactorial = current;
	}
	cout << current * powNum((Kfactorial * N_Kfactorial)%MOD, MOD - 2) % MOD;
}