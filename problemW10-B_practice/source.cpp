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
		vector<int> matryo(N+1, 0);
		vector<int> answer(N + 1,0); // max
		int answer_max = 0;
		for (int i = 1; i <= N; i++)
		{
			int input;
			cin >> input;
			matryo[i] = input;
		}
		
		
		for (int i = 1; i <= N; i++)
		{
			int max = 0;
			for (int j = 0; j < i; j++)
			{
				if (matryo[j] < matryo[i])
				{
					//cout << matryo[j] << " ";
					if (max < answer[j])
						max = answer[j];
				}
			}
			//cout << endl;
			answer[i] = max + 1;
			if (answer_max < max + 1)
				answer_max = max + 1;
		}
		cout << answer_max << endl;
	}
}