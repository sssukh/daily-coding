#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define MOD 1000000007
vector<vector<int>> fibo = { {0,1},{1,1} };
vector<vector<int>> mult_vector(vector<vector<int>>& a, vector<vector<int>>& b)
{
	vector<vector<int>> ret(2, vector<int>(2, 0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				ret[i][j] =((ll)ret[i][j]+ ((ll)a[i][k] * b[k][j])) % MOD;
			}
		}
	}
	return ret;
}

vector<vector<int>> getFibo(ll pow)
{
	if (pow == 0)
	{
		return { {1,0},{0,1} };
	}
	if (pow == 1)
	{
		return fibo;
	}
	vector<vector<int>> tmp = getFibo(pow / 2);
	tmp = mult_vector(tmp, tmp);
	if (pow % 2 > 0)
	{
		return mult_vector(tmp, fibo);
	}
	else
	{
		return tmp;
	}
}


int main()
{
	ll n;
	cin >> n;
	vector<vector<int>> answer = getFibo(n-1);
	cout << mult_vector(answer, fibo)[1][0];
}