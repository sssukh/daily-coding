#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, S, left, right,total,minLen;
	cin >> N >> S;
	vector<int> nums(N);
	minLen = N + 1;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		nums[i] = input;
	}
	left = right = 0;
	total = nums[0];
	while (true)
	{
		if (total < S)
		{
			if (right < N - 1)
			{
				++right;
				total += nums[right];
			}
			else
				break;
		}
		else
		{
			minLen = min(minLen, right - left + 1);
			total -= nums[left];
			++left;
		}
	}
	cout << (minLen == N + 1 ? 0 : minLen);
}