#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> nums(N+1,0);
	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		nums[i] = input + nums[i - 1];
	}
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << nums[end] - nums[start - 1] << "\n";
	}
}