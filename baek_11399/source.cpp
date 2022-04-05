#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int N,ret=0,tmp=0;
	cin >> N;
	vector<int> time(N);
	for (int i = 0; i < N; i++)
	{
		int tmp_time;
		cin >> tmp_time;
		time[i] = tmp_time;
	}
	sort(time.begin(), time.end());
	for (int i = 0; i < N; i++)
	{
		tmp += time[i];
		ret += tmp;
	}
	cout << ret;
}