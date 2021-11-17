#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}

void getAnswer(int qty, vector<int>& alp, vector<pair<string, int>>& words, int& answer)
{
	
	vector<int> cases(words.size() - qty, 0);
	for (int i = 0; i < qty; i++)
		cases.push_back(1);
	do
	{
		int score = 0;
		bool out = false;
		vector<int> current = alp;
		for (int i = 0; i < words.size(); i++)
		{
			
			if (cases[i] == 1)
			{
				
				string tmp = words[i].first;
				for (int j = 0; j < tmp.size(); j++)
				{
					if (--current[tmp[j] - 'a'] < 0)
					{
						out = true;
						break;
					}
				}
				if (out)
					break;
				score += words[i].second;
			}
		}
		if (!out&&answer<score)
		{
			answer = score;
			return;
		}

	} while (next_permutation(cases.begin(), cases.end()));
}

int main()
{
	int answer = 0;
	vector<int> alp(26, 0);
	for (int i = 0; i < 26; i++)
	{
		int a;
		cin >> a;
		alp[i] = a;
	}
	int M;
	cin >> M;
	vector<pair<string, int>> words;
	for (int i = 0; i < M; i++)
	{
		string W;
		int S;
		cin >> W>>S;
		words.push_back(make_pair(W, S));
	}
	sort(words.begin(), words.end(), cmp);
	for (int i = 1; i <= M; i++)
	{
		getAnswer(i, alp, words, answer);
	}
	cout << answer << endl;
}