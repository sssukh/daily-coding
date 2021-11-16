#include<iostream>
#include<vector>
using namespace std;

void setPaper(int i, int j, vector<vector<pair<char, int>>>& paper, char color)
{
	
	if (paper[i - 1][j - 1].first != color || paper[i - 1][j].first != color || paper[i][j - 1].first != color)
	{
		paper[i][j].second = 1;
		
	}
	else
	{
		
		paper[i][j].second = min(min(paper[i][j - 1].second, paper[i - 1][j - 1].second), paper[i - 1][j].second)+1;
		//paper[i-1][j-1].second = paper[i][j-1].second = paper[i - 1][j].second = paper[i][j].second;
	}
}

void check(int i, int j, vector<vector<pair<char, int>>>& paper, int N,int& Rq, int& Bq)
{
	if (i == 0 || j == 0 || N == 0)
		return;

	//cout << "size : " << N << endl;
	if (paper[i][j].second >= N)
	{
		if (paper[i][j].first == 'R')
		{
			Rq++;
			//cout <<"color : R "<< i << " " << j << endl;
		}
		else
		{
			Bq++;
			//cout <<"color : B " << i << " " << j << endl;
		}
	}
	else
	{
		/*
		check(i, j, paper, N / 2, Rq, Bq);
		check(i, j / 2, paper, N / 2, Rq, Bq);
		check(i / 2, j, paper, N / 2, Rq, Bq);
		check(i / 2, j / 2, paper, N / 2, Rq, Bq);
		*/
		check(i, j, paper, N / 2, Rq, Bq);
		check(i-N/2, j, paper, N / 2, Rq, Bq);
		check(i, j-N/2, paper, N / 2, Rq, Bq);
		check(i-N/2, j-N/2, paper, N / 2, Rq, Bq);

	
	}

}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<vector<pair<char, int>>> paper(N + 1, vector<pair<char, int>>(N + 1, { ' ',0 }));
		int R = 0,B = 0,Rq=0,Bq=0;						// 빨간색, 파란색 개수,빨간색, 파란색 종이의 개수

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				char input;
				cin >> input;
				if (input == 'R')
				{
					R++;
					paper[i][j].first = 'R';
					
				}
				else
				{
					B++;
					paper[i][j].first= 'B';
					
				}
				if (i == 1 || j == 1)
					paper[i][j].second = 1;
				else
					setPaper(i, j, paper, input);
					
				
				
			}
			
			
		}
		check(N, N, paper, N, Rq, Bq);
		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cout << paper[i][j].second << "\t";
			cout << "\n\n\n";
		}
		*/
		cout << Rq << " " << R << " " << Bq << " " << B << endl;
	}
}