#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;
	vector<vector<int>> record;
	vector<int> temp(26, 0);
	for (int i = 0; i < S.size(); i++)
	{
		
		++temp[S[i] - 'a'];
		record.push_back(temp);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		char alpha;
		cin >> alpha;
		int l, r;
		cin >> l >> r;
		if (l == 0)
			cout << record[r][alpha - 'a'] << "\n";
		else
			cout << record[r][alpha - 'a'] - record[l-1][alpha - 'a'] << "\n";
	}
}