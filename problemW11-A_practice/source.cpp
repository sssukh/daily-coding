#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}
void check(int qty, vector<int>& alps, vector<pair<string, int>>& words,int M,int& answer)
{
	
	vector<int> com(M - qty, 0);
	for (int i = 0; i < qty; i++)
		com.push_back(1);
	do
	{
		vector<int> tmp = alps;
		bool flag = true;
		int result = 0;
		for (int i = 0; i < M; i++)
		{
			if (com[i]==1)
			{
				for (int j = 0; j < words[i].first.size(); j++)
				{
					if (--tmp[words[i].first[j] - 'a'] < 0)
					{
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
				result += words[i].second;
			}
		}
		if (flag && answer < result)
		{
			answer = result;
			return;
		}
	} while (next_permutation(com.begin(), com.end()));
}

int main()
{
	vector<int> alps(26, 0);
	for (int i = 0; i < 26; i++)
	{
		int input;
		cin >> input;
		alps[i] = input;
	}
	int M;
	cin >> M;
	vector<pair<string, int>> words;
	for (int i = 0; i < M; i++)
	{
		string word;
		int score;
		cin >> word >> score;
		words.push_back(make_pair(word, score));
	}
	sort(words.begin(), words.end(), cmp);
	int answer = 0;
	for (int i = 1; i < M; i++)
	{
		check(i, alps, words, M,answer);
	}
	cout << answer << endl;
}