#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getWeights(vector<int>& items,int M)
{
	vector<int> weights;
	for (int i = 0; i <= items.size(); i++)
	{
		vector<bool> cases(items.size(), 0);
		fill(cases.end() - i, cases.end(), true);
		do
		{
			long long total = 0;
			for (int i = 0; i < cases.size(); i++)
			{
				if (cases[i])
					total += items[i];
			}
			if (total <= M)
				weights.push_back(total);
		} while (next_permutation(cases.begin(), cases.end()));
	}
	sort(weights.begin(), weights.end());
	return weights;
}

int main()
{
	int N, M , ret =0;
	cin >> N >> M;
	vector<int> items(N);
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		items[i] = input;
	}
	
	vector<int> forward(items.begin(), items.begin() + N / 2);
	vector<int> backward(items.begin() + N / 2, items.end());

	vector<int> forward_values = getWeights(forward,M);
	vector<int> backward_values = getWeights(backward,M);
	

	for (int i = 0; i < forward_values.size(); i++)
	{
		int mid,left = 0, right = backward_values.size() - 1, target = M-forward_values[i];
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (backward_values[mid] > target)
				right = mid - 1;
			else if (backward_values[mid] == target)
				break;
			else
				left = mid + 1;
		}
		while (backward_values[mid] > target)
			--mid;
		ret += mid + 1;
	}
	cout << ret;
}