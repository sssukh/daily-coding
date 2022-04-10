#include<iostream>
#include<vector>
using namespace std;

void make_seq(vector<int>& seq, int current , int N, int M)
{
	if (seq.size() == M)
	{
		//Ãâ·Â
		for (int i = 0; i < M; i++)
		{
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = current; i <= N; ++i)
	{
		seq.push_back(i);
		make_seq(seq, i, N, M);
		seq.pop_back();
	}
	return;

}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> seq;
	make_seq(seq, 1, N, M);
}