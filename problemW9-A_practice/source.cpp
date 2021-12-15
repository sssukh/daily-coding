#include<iostream>

using namespace std;

pair<long,long> getAnswer(int X, int N, int M)
{
	if (N == 1)
		return { X % M,X%M };
	pair<long, long> tmp = getAnswer(X,N/2,M);
	

	if (N % 2)//odd
	{
		return { (X + X * (tmp.second + 1) * tmp.first) % M,X * tmp.second * tmp.second % M };
	}
	else//even
	{
		
		return{ (tmp.first * (tmp.second + 1)) % M,tmp.second * tmp.second % M };
	}
	
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int X, N, M;
		cin >> X >> N >> M;
		cout << getAnswer(X, N, M).first << endl;
	}
}