#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> getFail(string str)
{
	vector<int> result(str.size(),0);
	for (int i = 1,j = 0; i < str.size(); i++)
	{
		while (j > 0 && str[i] != str[j])
		{
			j = result[j - 1];
		}
		if (str[i] == str[j])result[i] = ++j;
	}
	return result;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N, M;
	cin >> N >> M;
	vector<string> board(N, "");
	vector<string> words(M, "");
	string read = "";
	
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		board[i] = input;
		read += input + "$";
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			read += board[j][i];
		}
		read += "$";
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			read += board[N - 1 - i + j][j];
		}
		read += "$";
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; i + j < N; j++)
		{
			read += board[j][i + j];
		}
		read += "$";
	}
	for (int i = 0; i < M; i++) 
	{
		string input;
		cin >> input;
		vector<int> fail = getFail(input);
		bool answer = 0;
		for (int j = 0, k = 0; j < read.size(); j++)
		{
			while (k > 0 && input[k] != read[j])
			{
				k = fail[k - 1];
			}
			if (input[k] == read[j])
			{
				if (k == input.size() - 1)
				{
					answer = 1;
					break;
				}
				else
					k++;
			}
		}
		cout << answer << endl;
	}

	
	

}