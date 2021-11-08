#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAnswer(int top, int idx, int n, int& answer, vector<int>& matryos,vector<pair<int,int>>& mark)
{
	if (idx >= matryos.size())
	{
		if (answer < n)
			answer = n;
		return;
	}
	if (top >= mark[idx].first && n < mark[idx].second)
		return;
	if (n > mark[idx].second)
		mark[idx].second = n;
	//cout << idx << endl;
	if (top < matryos[idx])
	{
		getAnswer(matryos[idx], idx + 1, n + 1, answer, matryos,mark);
		getAnswer(top, idx + 1, n, answer, matryos,mark);
	}
	else
		getAnswer(top, idx + 1, n, answer, matryos,mark);
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> matryos; //val,idx
		vector<pair<int, int>> sorted;
		vector<pair<int, int>> mark;
		vector<int> s;
		int answer = 1;
		for (int i = 0; i < N; i++)
		{
			int input;
			cin >> input;
			matryos.push_back(input);
			//mark.push_back(make_pair(input, 0));
			sorted.push_back(make_pair(input, 1));
		}
		//getAnswer(0, 0, 0,answer, matryos, mark);
		reverse(sorted.begin(), sorted.end());
		
		for (int i = 1; i < N; i++)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (sorted[i].first < sorted[j].first&&sorted[i].second<sorted[j].second+1)
				{
					//cout << sorted[j].first << " " << sorted[i].first << endl;
					sorted[i].second = sorted[j].second + 1;
					if (answer < sorted[i].second)
						answer = sorted[i].second;
					
				}
				
			}
		}
		//for (pair<int, int> p : sorted)
			//cout << p.first << " " << p.second << endl;

		cout << answer << endl;
	}

}