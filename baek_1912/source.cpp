#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);// ���� ���� ������ ���� ���� �ִ밪�� ����
	int mx;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		nums[i] = input;
	}
	mx = nums[0];
	for (int idx = 1; idx < n; idx++)
	{
		if (nums[idx - 1] > 0)
		{
			nums[idx] += nums[idx - 1];
		}
		mx = max(mx, nums[idx]);
	}
	cout << mx << endl;
}