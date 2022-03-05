#include <iostream>
using namespace std;

int modular(int a, int b)
{
	if (b == 1)
		return a % 10;
	int tmp = modular(a, b / 2) % 10;
	if (b % 2)
	{
		return (tmp * tmp * modular(a, 1)) % 10;
	}
	else
	{
		return (tmp * tmp) % 10;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		int answer = modular(a, b);
		if (answer == 0)
			cout << 10 << endl;
		else
			cout << answer << endl;
	}
}