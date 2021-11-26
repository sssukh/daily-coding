#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> map;
vector<string> words;
vector<bool> exists;

void check(vector<int>& idx_list,int x, int y)
{
	vector<pair<int, int>> dir = { {0,1},{1,0},{1,1} };
	
	for (int i = 0; i < 3; i++)							//모든 방향 검색
	{
		int addx = dir[i].first;
		int addy = dir[i].second;
		int tmp_x = x;
		int tmp_y = y;
		for (int j = 0; j < idx_list.size(); j++)		//해당하는 char로 시작하는 모든 단어와 비교
		{
			string tmp = words[idx_list[j]];
			
			int k;
			for (k = 0; k < tmp.size(); k++)		//단어 비교
			{
				if (tmp_x >= map.size() || tmp_y >= map.size() || tmp[k] != map[tmp_x][tmp_y])
				{
					tmp_x = x;
					tmp_y = y;
					break;
				}
				tmp_x += addx; tmp_y += addy;
			}
			if (k == tmp.size())
			{
				exists[idx_list[j]] = 1;
				idx_list.erase(idx_list.begin() + j);
				j--;
				break;
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	//vector<string> map(N,"");
	unordered_map<char, vector<int>> hash;
	//vector<string> words;
	//vector<bool> exists(M, 0);
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		//map[i] = input;
		map.push_back(input);
	}
	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		words.push_back(input);
		hash[input[0]].push_back(i);
		exists.push_back(0);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!hash[map[i][j]].empty())			//시작하는 단어가 존재하면
			{
				//cout << i << " " << j <<" "<<map[i][j]<< endl;
				check(hash[map[i][j]], i, j);
			}
		}
	}
	for (int i = 0; i < M; i++)
		cout << exists[i] << endl;
}