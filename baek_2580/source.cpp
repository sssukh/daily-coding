#include<iostream>
#include<vector>
using namespace std;

vector<int> check(vector<vector<int>>& sdoku, int row, int col)
{
	int start_row = row - row % 3;
	int start_col = col - col % 3;
	vector<int> num_list(10,0);
	vector<int> ret;
	for (int i = 0; i < 9; i++)
	{
		if (sdoku[row][i])
			num_list[sdoku[row][i]] = sdoku[row][i];
		if (sdoku[i][col])
			num_list[sdoku[i][col]] = sdoku[i][col];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sdoku[i + start_row][j + start_col])
				num_list[sdoku[i + start_row][j + start_col]] = sdoku[i + start_row][j + start_col];
		}
	}
	for (int i = 1; i < 10; ++i)
	{
		if (num_list[i] == 0)
			ret.push_back(i);
	}
	return ret;
}

void writeNum(vector<vector<int>>& sdoku, vector<pair<int, int>>& blank, int idx, bool& is_full)
{
	if (is_full)
		return;
	if (idx == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sdoku[i][j] << " ";
			}
			cout << "\n";
		}
		is_full = true;
		return;
	}
	int row = blank[idx].first;
	int col = blank[idx].second;
	vector<int> get_candidates = check(sdoku, row, col);
	for (int i = 0; i < get_candidates.size(); i++)
	{
		sdoku[row][col] = get_candidates[i];
		writeNum(sdoku, blank, idx + 1,is_full);
		sdoku[row][col] = 0;
	}
}
int main()
{
	vector<vector<int>> sdoku(9, vector<int>(9));
	vector<pair<int, int>> blank;
	bool is_full = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 ; j++)
		{
			int input;
			cin >> input;
			sdoku[i][j] = input;
			if (input == 0)
				blank.push_back({ i,j });
		}
	}
	writeNum(sdoku, blank, 0,is_full);
}