#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;





void check(vector<int>& alpha_t,vector<pair<string, int>>& board, int idx,int sum_score,int& answer,unordered_map<char,int>& table)
{
	if (idx >= board.size())
	{
		if (answer < sum_score)
			answer = sum_score;
		return;
	}
	vector<int> temp = alpha_t;
	check(temp, board, idx + 1, sum_score, answer,table);
	int size = board[idx].first.size();
	string tmp = board[idx].first;
	for (int i = 0; i < size; i++)
	{
		if (--temp[table[tmp[i]]]<0)
		{
			if (answer < sum_score)
				answer = sum_score;
			return;
		}
	}
	check(temp, board, idx + 1, sum_score+board[idx].second, answer,table);
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);




	int N = 26;	
	int idx = 0;
	unordered_map<char, int> table;								//알파벳을 alpha의 인덱스로 변환
	for (char current = 'a'; current <= 'z'; current++)			//테이블에 알파벳저장
	{
		table[current] = idx;
		idx++;
	}
	vector<int> alpha(26, 0);									//알파벳의 개수
	for (int i = 0; i < N; i++)
	{
		int qty;
		cin >> qty;
		alpha[i] = qty;
	}
	int M;
	cin >> M;
	vector<pair<string, int>> board(M, { "",0 });			//영어단어, 점수
	for (int i = 0; i < M; i++)
	{
		string word;
		int score;
		cin >> word>>score;
		board[i].first = word;
		board[i].second = score;
	}
	//vector<int> tmp(26,0);
	
	int answer = 0;
	check(alpha, board, 0, 0, answer,table);
	cout << answer << endl;

}