#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> maze;
	vector<vector<int>> current_move(N, vector<int>(M, 0));
	queue<vector<int>> q;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		maze.push_back(tmp);
	}
	q.push({ 0, 0, 1 });
	while (!q.empty())
	{
		vector<int> tmp = q.front(); q.pop();
		if (tmp[0] >= 0 && tmp[0] < N && tmp[1] >= 0 && tmp[1] < M &&
			maze[tmp[0]][tmp[1]] == '1'&&current_move[tmp[0]][tmp[1]]==0)
		{
			current_move[tmp[0]][tmp[1]] = tmp[2];
			q.push({ tmp[0] + 1,tmp[1],tmp[2] + 1 });
			q.push({ tmp[0] - 1,tmp[1],tmp[2] + 1 });
			q.push({ tmp[0], tmp[1] + 1,tmp[2] + 1 });
			q.push({ tmp[0], tmp[1] - 1,tmp[2] + 1 });
		}
	}
	cout << current_move.back().back() << endl;
}