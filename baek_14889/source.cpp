#include<iostream>
using namespace std;

int synergy[21][21];
int team_start, team_link,ret=1e8,current_team_start_size=0;
bool is_team_start[21] = { 0, };

void addSynergy(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (is_team_start[i] == is_team_start[j])
			{
				if (is_team_start[i])
				{
					team_start += synergy[i][j];
				}
				else
				{
					team_link += synergy[i][j];
				}
			}
		}
	}
}

void make_team_start(int N, int idx)
{
	if (current_team_start_size == N / 2)
	{
		addSynergy(N);
		ret = min(ret, abs(team_start - team_link));
		
		team_start = team_link = 0;
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		is_team_start[i] = true;
		current_team_start_size++;
		make_team_start(N, i + 1);
		is_team_start[i] = false;
		current_team_start_size--;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int input;
			cin >> input;
			synergy[i][j] = input;
		}
	}
	make_team_start(N, 1);
	cout << ret;

}