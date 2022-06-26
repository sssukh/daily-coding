#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, M;
	long long ret = 0;
	cin >> N >> M;
	vector<int> nums(1,0);
	vector<int> mods(M, 0);
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		nums.push_back((nums.back() + input) % M);
		++mods[nums.back()];
		if (nums.back() == 0) ++ret;
	}
	for (int i=0;i<M;i++)
	{
			ret += (long long)mods[i] * (mods[i]-1) / 2;
	}
	cout << ret;
}


