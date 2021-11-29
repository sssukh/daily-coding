#include <iostream>
#include <vector>
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
		vector<int> message_list;
		unordered_map<int, int> sender_list;
		vector<int> answer;
		for (int i = 0; i < M; i++)
		{
			int sender;
			cin >> sender;
			message_list.push_back(sender);
		}
		while (!message_list.empty())
		{
			sender_list[message_list.back()]++;
			answer.push_back(N - sender_list.size());
			message_list.pop_back();
		}
		for (int i = answer.size() - 1; i >= 0; i--)
			cout << answer[i] << endl;
	}
}