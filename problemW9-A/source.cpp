#include<iostream>
#include<vector>
using namespace std;

pair<long long, long long> sol(long long x, long long exp, long long m) // x^exp,x+....+x^exp
{
	
	if (exp == 1)
		return { x % m,x % m };
	pair<long long, long long> tmp = sol(x, exp / 2, m);
	//cout << exp << " " << tmp.first << " " << tmp.second << endl;
	if (exp % 2==0) // 지수가 짝수이면
	{
		
		return { (tmp.first * tmp.first) % m,((1 + tmp.first) * (tmp.second)) % m };
	}
	else
	{
		
		return { (x * tmp.first * tmp.first) % m,(x + x * (1 + tmp.first) * tmp.second) % m };
	}

}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{

		long long X, N, M;
		cin >> X >> N >> M;
		long long answer = 0;
		if (M == 0)
		{
			cout << 0 << endl;
			continue;
		}
		
		if (X > 1)
		{
			answer = sol(X, N, M).second;
		}
		else
			answer = N%M;
		cout << answer<< endl;
	}
}