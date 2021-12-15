#include<iostream>
#include<vector>
using namespace std;

int DFS(vector<vector<int>>& compare, int start, vector<int>& answer,vector<bool>& visited)
{
	
		int result = 0;
		for (int i = 0; i < compare.size(); i++)
		{
			if (compare[start][i] == 1&&!visited[i])
			{
				visited[i] = 1;
				result += DFS(compare, i, answer,visited);
			}
		}
		answer[start] = result;
		return result + 1;
	
}



int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> compare(N+1,vector<int>(N+1,0));
		vector<int> answer(N + 1, 0);
		for (int i = 0; i < M; i++)
		{
			int A, B;
			cin >> A >> B;
			compare[A][B] = 1;
		}
		for (int i = 1; i <= N; i++)
		{
			vector<bool> visited(N + 1, 0);
			DFS(compare, i, answer, visited);
			cout << answer[i] << " ";
		}
		cout << endl;
	}
	
}