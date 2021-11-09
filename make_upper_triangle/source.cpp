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
	cout << "Matrix�� ũ�⸦ �Է��Ͻÿ�(N x N���� N�� �Է�) : ";
	cin >> N;
	vector<vector<int>> matrix(N,vector<int>(N,0));
	cout << "element�� �Է��Ͻÿ�" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			matrix[i][j] = input;
		}
	}

	for (int i = 1; i < N; i++)				//���� ��
	{
		for (int j = 0; j < i; j++)			//���� ��
		{
			int most_left = matrix[i][j];
			if (most_left==0)				//diagonal�� �ƴϸ鼭 ���� ������ 0�̸� �Ѿ;
				continue;
			int div = matrix[j][j];
			
			if (div == 0)					//�����ϴ� ���� diagonal�� 0�̸� swap
			{
				row_swap(matrix, i, j);
				continue;
			}
			for (int k = j; k < N; k++)		//most left ���� �����ϸ鼭 row operation
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