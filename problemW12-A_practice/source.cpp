#include <iostream>
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
		
		int input1,answer;
		cin >> input1;
		vector<vector<int>> triangle(1, { input1 });
		for (int i = 1; i < N; i++)
		{
			vector<int> tmp;
			for (int j = 0; j <= i; j++)
			{
				
				int input;
				cin >> input;
				if (j == 0)
				{
					input += triangle[i - 1][j];
				}
				else if (j == i)
				{
					input += triangle[i - 1][j - 1];
				}
				else
				{
					input += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
				}
				tmp.push_back(input);
			}
			triangle.push_back(tmp);
		}
		answer = triangle[N - 1][0];
		for (int i = 1; i < N; i++)
		{
			answer = min(triangle[N - 1][i], answer);
		}
		cout << answer << endl;
	}
}