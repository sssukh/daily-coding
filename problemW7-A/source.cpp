#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;

void check(int, vector<vector<bool>>&,unordered_map<int,int>&);

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<bool>> result(N,vector<bool>(N,0));
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			result[a-1][b-1] = true;
		}
		for (int i = 0; i < N; i++)
		{
			unordered_map<int,int> visited;
			check(i, result, visited);
			cout << visited.size() << " ";
			
		}
		
		cout << endl;
	}
}
void check(int idx, vector<vector<bool>>& result,unordered_map<int,int>& visited)
{
	for (int i = 0; i < result.size(); i++)
	{
		if (result[idx][i] == true&&visited[i]==0)
		{
			visited[i] = 1;
			check(i, result, visited);
		}
	}
}