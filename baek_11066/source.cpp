#include<iostream>
#include<vector>
using namespace std;
#define INTMAX 1e9



int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int K;
		cin >> K;
		vector<vector<int>> novel(K + 1, vector<int>(K + 1,0));
		vector<vector<int>> totalCost(K + 1, vector<int>(K + 1, 0));
		for (int i = 1; i <= K; i++)
		{
			int size;
			cin >> size;
			novel[i][i] = size;
		}

		for (int qty = 1; qty < K; qty++)
		{
			for (int start = 1; start + qty <= K; start++)
			{
				totalCost[start][start + qty] +=totalCost[start][start]+
					totalCost[start + 1][start + qty] + 
					novel[start][start]+novel[start+1][start+qty];
				novel[start][start + qty] = novel[start][start] +
					novel[start + 1][start + qty];
				for (int middle = 1; middle < qty; middle++)
				{
					int crt = totalCost[start][start + middle] + totalCost[start + middle + 1][start + qty] +
						novel[start][start + middle] + novel[start + middle + 1][start + qty];
					
					if (totalCost[start][start + qty] > crt)
					{
						totalCost[start][start + qty] = crt;
						novel[start][start + qty] = novel[start][start + middle] +
							novel[start + middle + 1][start + qty];
					}
					
				}
			}
		}
		
		cout << totalCost[1][K] << "\n";
	}
}