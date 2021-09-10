#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;  //친구들의 수 N, 교수님이 말씀하신 단어 M
		cin >> N >> M;
		vector<string> words; //교수님이 말씀하신 문장
		vector<queue<string>>students; //친구들이 적은 단어들
		string tmp;
		while (M--)
		{
			cin >> tmp;
			words.push_back(tmp);
		}
		for(int i=0;i<N;i++)
		{
			int K; 
			cin >> K;

			queue<string> word; //친구 한명이 적은 단어들
			for(int i=0;i<K;i++)
			{
				string S;
				cin >> S;
				word.push(S);
			}
			students.push_back(word);
		}

		//여기까지 input
		bool possible = true;
		for (string a : words)
		{
			bool check = false; //친구들이 적은 단어에 있으면 true 없으면 false
			for (int i = 0; i < N; i++)
			{
				if (a == students[i].front())
				{
					check = true;
					students[i].pop();
					break;
				}
			}

			if (!check)
			{
				possible = false;
				cout << 0 << endl;
				break;
			}
		}

		if (possible)
			cout << 1 << endl;


	}
}