#include<iostream>
#include<vector>
using namespace std;

pair<int, int> postorder(int, int, vector<vector<int>>&,vector<bool>&);

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<vector<int>> town(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < n - 1; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			town[u][v] = d;
			town[v][u] = d;
		}
		vector<bool> visit(n + 1, false);
		cout << postorder(1, 0, town,visit).first << "\n";
	}
}
pair<int, int> postorder(int idx, int value, vector<vector<int>>& town,vector<bool>& visit)
{
	visit[idx] = true;										//�湮�� ��� üũ
	pair<int, int> tmp;										//���� �� ���� length�� ���� ū �� ���� tmp
	int fir_max = 0;										//������忡�� ���� �� ����
	int sec_max = 0;										//������忡�� �ι�°�� �� ����
	int length = 0;											//������忡�� �޾ƿ� ���� �� length
	for (int i = 0; i < town.size(); i++)
	{
		if (town[idx][i] > 0 && visit[i]==false)
		{
			tmp = postorder(i, town[idx][i],town,visit);	//���� visit�ؼ� leaf�� ����
			if (tmp.second > fir_max)						//������忡�� ���� �� ���̿� �ι�°�� �� ���� ���
			{
				sec_max = fir_max;
				fir_max = tmp.second;
			}
			else if (tmp.second > sec_max)
			{
				sec_max = tmp.second;
			}
			if (length < tmp.first)							//������忡�� ���� �� length ���
				length = tmp.first;
		}
	}
	if (length < fir_max + sec_max)							//������忡�� ���� �� ���̿� ���� ���� ��
		length = fir_max + sec_max;
	tmp.first = length;
	tmp.second = fir_max + value;							//������忡�� ���� �� ���̿��� ���� ���� ���ϱ�
	//cout <<idx<<" "<< tmp.first << " " << tmp.second << endl;
	return tmp;
}