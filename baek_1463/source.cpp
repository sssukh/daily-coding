#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> numbers(N+1);
	numbers[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (i % 6 == 0)
		{
			numbers[i] = min(numbers[i / 2], min(numbers[i / 3], numbers[i - 1]))+1;
		}
		else if (i % 2 == 0 && i % 3 != 0)
		{
			numbers[i] = min(numbers[i / 2], numbers[i - 1])+1;
		}
		else if (i % 2 != 0 && i % 3 == 0)
		{
			numbers[i] = min(numbers[i / 3], numbers[i - 1])+1;
		}
		else
		{
			numbers[i] = numbers[i - 1]+1;
		}
	}
	cout << numbers[N] << endl;

}