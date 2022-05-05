#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M;
	cin >> N;
	//multiset<int> cards;
	//vector<int> cards;
	map<int, int> cards;
	for (int i = 0; i < N; i++)
	{
		int card;
		cin >> card;
		++cards[card];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		cout << cards[num] << " ";
	}
}