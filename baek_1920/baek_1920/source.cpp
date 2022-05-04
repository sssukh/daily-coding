#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool bs(vector<int>& nums, int num)
{
	int left = 0;
	int right = nums.size() - 1;
	int mid = (left + right) / 2;
	bool ret = false;
	while (left <= right)
	{
		if (num < nums[mid])
		{
			right = mid-1;
		}
		else if (num > nums[mid])
		{
			left = mid + 1;
		}
		else
		{
			ret = true;
			break;
		}
		mid = (left + right) / 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		nums[i] = input;
	}
	sort(nums.begin(), nums.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int current;
		cin >> current;
		if (bs(nums, current))
			cout << "1\n";
		else
			cout << "0\n";
	}
}