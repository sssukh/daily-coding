#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> numbers(N);
	vector<int> fromLeft(N);
	vector<int> fromRight(N);
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		numbers[i] = input;
	}
	for (int i = 0; i < N; i++)
	{
		int maxLen = 0;
		for (int j = 0; j < i; j++)
		{
			if (numbers[i] > numbers[j])
			{
				maxLen = max(maxLen, fromLeft[j]);
			}
		}
		fromLeft[i] = maxLen + 1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		int maxLen = 0;
		for (int j = N - 1; j > i; j--)
		{
			if (numbers[i] > numbers[j])
			{
				maxLen = max(maxLen, fromRight[j]);
			}
		}
		fromRight[i] = maxLen + 1;
		ret = max(ret, fromLeft[i] + fromRight[i]);
	}
	cout << ret - 1;
}