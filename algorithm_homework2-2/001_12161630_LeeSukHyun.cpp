#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> preprocessing(string pattern)
{
	vector<int> ret(26, -1);
	for (int i = 0; i < pattern.size(); i++)
	{
		if(pattern[i]!='X')
			ret[pattern[i] - 'a'] = i;
	}
	return ret;
}

int main()
{
	string book;
	cin >> book;
	string pattern;
	cin >> pattern;
	vector<int> lastOccurenceFunction = preprocessing(pattern);
	vector<int> start_idx;
	int i = pattern.size() - 1, j = pattern.size() - 1;
	while (i <= book.size() - 1)
	{
		if (book[i] == pattern[j]||pattern[j]=='X')
		{
			// pattern 일치
			if (j == 0)
			{
				int tmp = i + pattern.size() -1 -j;
				start_idx.push_back(i);
				int l = lastOccurenceFunction[book[i+pattern.size()] - 'a'];
				i = i + pattern.size() - min(j, 1 + l);
				j = pattern.size() - 1;
				cout << i- tmp << " ";
			}
			// pattern일치할때까지 계속 비교
			else
			{
				--i;
				--j;
			}
		}
		else
		{
			int tmp = i + pattern.size() -1 -j;
			int l = lastOccurenceFunction[book[i]-'a'];
			i = i + pattern.size() - min(j, 1 + l);
			j = pattern.size()-1;
			cout << i - tmp << " ";
		}
	}
	cout << "\n";
	for (int i : start_idx)
		cout << i << " ";
	

}