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
		int N, M;  //ģ������ �� N, �������� �����Ͻ� �ܾ� M
		cin >> N >> M;
		vector<string> words; //�������� �����Ͻ� ����
		vector<queue<string>>students; //ģ������ ���� �ܾ��
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

			queue<string> word; //ģ�� �Ѹ��� ���� �ܾ��
			for(int i=0;i<K;i++)
			{
				string S;
				cin >> S;
				word.push(S);
			}
			students.push_back(word);
		}

		//������� input
		bool possible = true;
		for (string a : words)
		{
			bool check = false; //ģ������ ���� �ܾ ������ true ������ false
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