#include<iostream>
#include<vector>
using namespace std;
// left<=  <right
long long get_rect(vector<int>& height, int left, int right)
{
	if (left==right)
	{
		return height[left];
	}
	int mid = (left + right) / 2;
	long long ret = max(get_rect(height, left, mid), get_rect(height, mid+1, right));
	int lo = mid, hi = mid + 1;
	int minMidHeight = min(height[lo], height[hi]);
	ret = max(ret, (long long)minMidHeight * (hi - lo + 1));
	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || height[hi+1] > height[lo-1]))
		{
			++hi;
			minMidHeight = min(minMidHeight, height[hi]);
		}
		else
		{
			--lo;
			minMidHeight = min(minMidHeight, height[lo]);
		}

		ret = max(ret, (long long)minMidHeight * (hi - lo + 1));
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;
	while (n!=0)
	{
		vector<int> height(n);
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			height[i] = input;
		}
		cout << get_rect(height, 0, n - 1) << endl;
		cin >> n;
	}
	
}