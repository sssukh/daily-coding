#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, M, mid, ret, height_lo = 0, height_hi = 1000000000;
	cin >> N >> M;
	vector<int> trees(N);
	for (int i = 0; i < N; i++)
	{
		int tree;
		cin >> tree;
		trees[i] = tree;
	}
	while (height_lo <= height_hi)
	{
		mid = (height_lo + height_hi) / 2;
		long long treeLen = 0;
		for (int i = 0; i < N; i++)
		{
			treeLen += max(0, trees[i] - mid);
		}
		if (treeLen >= M)
		{
			height_lo = mid + 1;
			ret = mid;
		}
		else
		{
			height_hi = mid - 1;
		}
	}
	cout << ret;
}