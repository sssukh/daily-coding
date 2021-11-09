#include <iostream>
#include <vector>
using namespace std;

void row_swap(vector<vector<int>>& matrix,int i, int j)
{
	vector<int> tmp = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = tmp;
}

int main()
{
	int N;
	cout << "Matrix의 크기를 입력하시오(N x N에서 N을 입력) : ";
	cin >> N;
	vector<vector<int>> matrix(N,vector<int>(N,0));
	cout << "element를 입력하시오" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			matrix[i][j] = input;
		}
	}

	for (int i = 1; i < N; i++)				//현재 행
	{
		for (int j = 0; j < i; j++)			//현재 열
		{
			int most_left = matrix[i][j];
			if (most_left==0)				//diagonal이 아니면서 가장 왼쪽이 0이면 넘어감;
				continue;
			int div = matrix[j][j];
			
			if (div == 0)					//빼야하는 행의 diagonal이 0이면 swap
			{
				row_swap(matrix, i, j);
				continue;
			}
			for (int k = j; k < N; k++)		//most left 열을 제거하면서 row operation
			{
				matrix[i][k] =matrix[i][k]*div -  matrix[j][k]  * most_left;
			}
		}
	}

	for (vector<int> v : matrix)
	{
		for (int i : v)
			cout << i << "\t";
		cout << "\n\n\n";
	}

}