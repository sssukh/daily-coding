#include <iostream>
#include<vector>
using namespace std;

void perm(vector<int>& arr,vector<bool>& visit,int count)
{
	if (arr.size() == count)
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i < visit.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr.push_back(i);
			perm(arr, visit, count);
			visit[i] = false;
			arr.pop_back();
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> arr;
	vector<bool> visited(N + 1);
	perm(arr, visited, M);
}