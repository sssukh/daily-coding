#include<iostream>
using namespace std;
#define ll long long

ll power(ll num, ll pow, ll mod)
{
	if (pow == 1)
	{
		return num % mod;
	}
	ll dividedNum = power(num, pow / 2, mod);
	if (pow % 2)
	{
		return (dividedNum * ((dividedNum*num)%mod)) % mod;
	}
	else
	{
		return (dividedNum * dividedNum) % mod;
	}
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout << power(a, b, c);
}