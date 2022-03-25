#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int M = N;
	int ret=0;
	while (M--)
	{
		int temp = M;
		int remain = M;
		while (remain > 0)
		{
			temp += remain % 10;
			remain /= 10;
		}
		if (temp == N)
			break;
	}
	for (int i = 0; i < 100; i++)
	{
		int tmp = M- i;
		int res = tmp;
		while (tmp > 0)
		{
			res += tmp % 10;
			tmp /= 10;
		}
		if (res == N)
			ret = M-i;
	}
	cout << ret;
}