#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> messenger;
		vector<int> answer;
		unordered_map<int, int> senders;
		for (int i = 0; i < M; i++)
		{
			int A;
			cin >> A;
			messenger.push_back(A);
		}
		while (!messenger.empty())
		{
			int tmp = messenger.back();
			messenger.pop_back();
			senders[tmp]++;
			answer.push_back(N - senders.size());
		}
		for (int i = answer.size() - 1; i >= 0; i--)
		{
			cout << answer[i] << endl;
		}
	}
}