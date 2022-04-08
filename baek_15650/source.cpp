#include<iostream>
#include<vector>
using namespace std;

void make_seq(vector<int>& seq, int cur, int M,int N)
{
	if (seq.size() == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << seq[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = cur; i <= N; i++)
	{
		seq.push_back(i);
		make_seq(seq, i + 1, M, N);
		seq.pop_back();
	}
	return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> seq;
	make_seq(seq, 1, M, N);
}