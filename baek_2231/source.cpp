#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int M = N;
	int ret=0;
	
	for (int i = 0; i < 100; i++)
	{
		int tmp = N- i;
		int res = tmp;
		while (tmp > 0)
		{
			res += tmp % 10;
			tmp /= 10;
		}
		if (res == N)
			ret = N-i;
	}
	cout << ret;
}