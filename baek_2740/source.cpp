#include<iostream>
using namespace std;

int N, M, K, mat1[100][100], mat2[100][100];

void multMatrix()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int current = 0;
			for (int k = 0; k < M; k++)
			{
				current += mat1[i][k] * mat2[k][j];
				
			}
			cout << current << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int elem;
			cin >> elem;
			mat1[i][j] = elem;
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int elem;
			cin >> elem;
			mat2[i][j] = elem;
		}
	}
	multMatrix();
}
