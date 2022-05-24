#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> arrSize(N, { 0,0 });
	vector<vector<int>> count(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		int r, c;
		cin >> r >> c;
		arrSize[i] = { r,c };
	}
	for (int qty = 1; qty < N; qty++)
	{
		for (int start = 0; start + qty < N; start++)
		{
			count[start][start + qty]= count[start][start] + count[start + 1][start + qty] +
				arrSize[start].first * arrSize[start].second * arrSize[start + qty].second;
			for (int mid = 1; mid < qty; mid++)
			{
				count[start][start + qty] = min(count[start][start + qty],
					count[start][start+mid]+count[start+mid+1][start+qty]+
					arrSize[start].first * arrSize[start + mid].second * arrSize[start + qty].second);
			}
		}
	}
	cout << count[0][N - 1];
}