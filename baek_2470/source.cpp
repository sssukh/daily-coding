#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N,left,right,sum=2000000001;
	cin >> N;
	vector<int> fluid(N);
	vector<int> ret(2);
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		fluid[i] = input;
	}
	sort(fluid.begin(), fluid.end(),less<int>());
	left = 0; right = N - 1;
	while (left < right)
	{
		if (abs(fluid[left] + fluid[right]) < sum)
		{
			ret[0] = fluid[left];
			ret[1] = fluid[right];
			sum = abs(fluid[left] + fluid[right]);
			
		}
		if (fluid[left] + fluid[right] < 0)
		{
			left++;
		}
		else if (fluid[left] + fluid[right] > 0)
		{
			right--;
		}
		else
		{
			left++;
			right--;
		}
	}
	cout << ret[0] << " " << ret[1];
}