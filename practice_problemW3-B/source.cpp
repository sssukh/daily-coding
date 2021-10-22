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
	visit[idx] = true;										//방문한 노드 체크
	pair<int, int> tmp;										//가장 긴 길이 length와 가장 큰 수 담을 tmp
	int fir_max = 0;										//인접노드에서 가장 긴 길이
	int sec_max = 0;										//인접노드에서 두번째로 긴 길이
	int length = 0;											//인접노드에서 받아온 가장 긴 length
	for (int i = 0; i < town.size(); i++)
	{
		if (town[idx][i] > 0 && visit[i]==false)
		{
			tmp = postorder(i, town[idx][i],town,visit);	//먼저 visit해서 leaf에 도달
			if (tmp.second > fir_max)						//인접노드에서 가장 긴 길이와 두번째로 긴 길이 얻기
			{
				sec_max = fir_max;
				fir_max = tmp.second;
			}
			else if (tmp.second > sec_max)
			{
				sec_max = tmp.second;
			}
			if (length < tmp.first)							//인접노드에서 가장 긴 length 얻기
				length = tmp.first;
		}
	}
	if (length < fir_max + sec_max)							//인접노드에서 가장 긴 길이와 현재 길이 비교
		length = fir_max + sec_max;
	tmp.first = length;
	tmp.second = fir_max + value;							//인접노드에서 가장 긴 길이에서 나의 길이 더하기
	//cout <<idx<<" "<< tmp.first << " " << tmp.second << endl;
	return tmp;
}