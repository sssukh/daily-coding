#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct info
{
	int row, col;
};

int main()
{
	int N;
	cin >> N;
	vector<string> houses(N);
	vector<int> ret;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		houses[i] = input;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (houses[i][j] == '1')
			{
				queue<info> q;
				q.push({ i,j});
				ret.push_back(0);
				while (!q.empty())
				{
					info current = q.front();
					q.pop();
					if (current.row>= 0 && current.row < N &&
						current.col>= 0 && current.col < N &&
						houses[current.row][current.col]=='1')
					{
						houses[current.row][current.col] ='0';
						++ret.back();
						q.push({ current.row + 1,current.col});
						q.push({ current.row - 1,current.col});
						q.push({ current.row, current.col + 1 });
						q.push({ current.row, current.col - 1 });
					}
				}

			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for (int i : ret)
		cout << i << "\n";
}