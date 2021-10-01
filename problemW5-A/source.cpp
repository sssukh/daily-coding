#include<iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> message;
		for (int i = 0; i < N; i++) 
		{
			int a;
			cin >> a;
			message.push_back(a);
		}

		vector<int> compare;
		
		for (int i = 0; i < N; i++)
		{
			bool is_signal = true;
			compare.push_back(message[i]);
			for (int j = i+1; j < N; j++)
			{
				if (compare[j % (i + 1)] != message[j])
				{
					is_signal = false;
					break;
				}
			}
			if (is_signal)
			{
				for (int v : compare)
					cout << v << " ";
				cout << endl;
				break;
			}
		}
	}
}


/*
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<string> message;

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			message.push_back(to_string(a));
		}
		string tmp = "";
		for (int i = 0; i < N; i++)
		{

			
			tmp += message[i];
			int message_checking_start = i+1;
			int idx = -1;
			while (message_checking_start < N)
			{
				string compare1 = tmp;
				string compare2 = "";
				int count = 0;

				for (int j = message_checking_start; j <= message_checking_start+i; j++)
				{
					if (j >= N)
						break;
					compare2 += message[j];
					count++;
				}

				if (compare2.size() < compare1.size())
				{
					compare1 = "";
					for (int j = 0; j < count; j++)
						compare1 += message[j];
				}

				if (compare1 == compare2)
				{
					message_checking_start += i+1;
				}
				else
				{
					break;
				}
				idx = i;
				
			}
			if (message_checking_start >= N)
			{
				if (idx == -1)
					idx = N - 1;
				for (int i = 0; i <= idx; i++)
				{
					cout << message[i] << " ";
				}
				cout << "\n";
				break;
			}
		}

	}
}
*/