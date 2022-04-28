#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> stack(N, 0);
	vector<int> ret(1,-1);
	vector<int> right;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		stack[i] = input;
	}
	right.push_back(stack.back());
	stack.pop_back();
	while (!stack.empty())
	{
		while (!right.empty()&&stack.back() >= right.back())
			right.pop_back();
		if (right.empty())
			ret.push_back(-1);
		else
			ret.push_back(right.back());
		right.push_back(stack.back());
		stack.pop_back();
	}
	for (auto iter = ret.crbegin(); iter != ret.crend(); iter++)
		cout << *iter << " ";
}