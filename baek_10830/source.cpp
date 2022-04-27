#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000

vector<vector<int>> multMatrix(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int N)
{
	vector<vector<int>> ret(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				ret[i][j] = (ret[i][j]+(mat1[i][k] * mat2[k][j])) % MOD;
			}
		}
	}
	return ret;
}

vector<vector<int>> powMatrix(int N, long long pow, vector<vector<int>>& mat)
{
	if (pow == 0)
	{
		vector<vector<int>> identity(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++)
			identity[i][i] = 1;
		return identity;
	}
	vector<vector<int>> current;
	if (pow % 2 > 0)
	{
		current = powMatrix(N, pow - 1, mat); // 여기에 mat 곱해주기
		current = multMatrix(current, mat, N);
	}
	else
	{
		current = powMatrix(N, pow / 2, mat);
		current = multMatrix(current, current, N);
	}
	/*
	cout << "current pow : " << pow << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << current[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	return current;
}

int main()
{
	int N;
	long long B;
	cin >> N >> B;
	vector<vector<int>> mat(N, vector<int>(N, 0));
	vector<vector<int>> ret;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			mat[i][j] = input;
		}
	}
	ret = powMatrix(N, B, mat);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
}