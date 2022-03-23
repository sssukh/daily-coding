#include <iostream>
#include <vector>
using namespace std;

void getMax(vector<int>& cards,vector<int>& picked, int idx, int& answer,int max)
{
	if (picked.size() == 3)
	{
		int sum = cards[picked[0]] + cards[picked[1]] + cards[picked[2]];
		if (sum > answer && sum <= max)
			answer = sum;
		return;
	}
	for (int i = idx; i < cards.size(); i++)
	{
		picked.push_back(i);
		getMax(cards, picked, i + 1, answer,max);
		picked.pop_back();
	}

}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> cards(N);
	vector<int> picked;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		cards[i] = input;
	}
	getMax(cards, picked, 0, answer,M);
	cout << answer;
}