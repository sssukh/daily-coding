#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, answer;
		cin >> N;
		vector<vector<int>> triangle(1,vector<int>(2,0));

		for (int i = 1; i <= N; i++)			//삼각형 입력받기
		{
			vector<int> triangle_input(1,0);
			for (int j = 1; j <= i; j++)
			{
				int input, tmp;
				cin >> input;
				
				if (j == 1)
				{
					tmp = triangle[i-1][j];
				}
				else if (j == i)
				{
					tmp = triangle[i-1][j - 1];
				}
				else
				{
					tmp = min(triangle[i - 1][j], triangle[i - 1][j - 1]);
				}
				triangle_input.push_back(input + tmp);
			}
			triangle.push_back(triangle_input);
		}
		answer = triangle[N][1];
		for (int i =2;i<=N;i++)
		{
			if (answer > triangle[N][i])
				answer = triangle[N][i];
		}
		cout <<answer << endl;
	}

}