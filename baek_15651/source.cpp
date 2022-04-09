#include<iostream>
#include<vector>
#include<string>
using namespace std;

void make_seq(vector<int>& seq,int M,int N)
{
	if (seq.size() == M)
	{
		string output = "";
		for (int i = 0; i < M; i++)
		{
			output +=to_string(seq[i])+" ";
		}
		cout << output<<"\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		seq.push_back(i);
		make_seq(seq, M, N);
		seq.pop_back();
	}
	return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> seq;
	make_seq(seq, M, N);
}