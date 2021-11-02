#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> is_possible( vector<vector<int>>& board,int turn)
{
	vector<pair<int, int>> result;
	vector<pair<int, int>> dir = { {1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1} };
	int boardSize = board.size();
	for (int i = 1; i < boardSize; i++)
	{
		for (int j = 1; j < boardSize; j++)
		{
			if (board[i][j] == turn)//흑 턴에 흑돌, 백 턴에 백돌이 i,j에 있으면
			{
				for (int k = 0; k < 8; k++)
				{
					int x = i + dir[k].first;
					int y = j + dir[k].second;
					bool my_turn=false;
					
					while (x >= 1 && y >= 1 && x < boardSize && y < boardSize)
					{
						if (board[x][y] == turn)
						{
							break;
						}
						else if (board[x][y] == -turn)
						{
							x += dir[k].first;
							y += dir[k].second;
							
							my_turn = true;
						}
						else
						{
							if (my_turn)
							{
								result.push_back(make_pair(x, y));
							}
							break;
						}
					}
					
				}
			}
		}
	}

	return result;
}

void flip(int r, int c, vector<vector<int>>& board, int turn)
{
	vector<pair<int, int>> dir = { {1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1} };
	int boardSize = board.size();
	
			for (int k = 0; k < 8; k++)
			{
				int x = r + dir[k].first;
				int y = c + dir[k].second;
				bool check = false;
				while (x >= 1 && y >= 1 && x < boardSize && y < boardSize)
				{
					
					if (board[x][y] == turn)
					{
						if (check)
						{
							
							while (!(x == r && y == c))
							{
								
								x -= dir[k].first;
								y -= dir[k].second;
								board[x][y] = turn;
								
							}
						}
							break;
					}
					else if (board[x][y] == -turn)
					{
						
						x = x + dir[k].first;
						y = y + dir[k].second;
						check = true;
						
					}
					else
					{
						break;
					}
				}
		
			}
	
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, Q;
		cin >> n >> Q;
		int turn = 1; // 흑돌부터 시작
		int count = 0;
		int answer;
		vector<vector<int>> board(n+1, vector<int>(n+1, 0));
		board[n / 2][n / 2] = 1; board[n / 2 + 1][n / 2 + 1] = 1;	//흑
		board[n / 2][n / 2 + 1] = -1; board[n / 2 + 1][n / 2] = -1;		//백
		while (Q&&count<2)
		{
			
			vector<pair<int, int>> myturn = is_possible(board, turn);

			//for (pair<int, int> p : myturn)
				//cout << "possible  "<<p.first << " " << p.second << endl;
			

			if (myturn.empty())
			{
				count++;
				turn = -turn;
				
				continue;
			}
			else
				count = 0;// 한명이라도 둘곳 있으면 count 초기화

			Q--;
			int r, c;
			
				cin >> r >> c;
				//pair<int, int> tmp = make_pair( r,c );

				for (pair<int, int> p : myturn)
				{
					if (r == p.first && c == p.second)
					{
						//cout << r << " " << c << " " << turn << endl;

						board[r][c] = turn;
						flip(r, c, board, turn);
						turn = -turn; //턴바꿈
						break;
					}
				}
				
			

			/*
			auto iter = find(myturn.begin(), myturn.end(), tmp);
			if (iter == myturn.end())
				continue;
			else
			{
				board[r][c] = turn;
				flip(r, c, board, turn);
				turn = -turn; //턴바꿈
			}
			*/
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						
						cout << board[i][j] << "\t";
					}
					cout << endl;
					cout << endl;
				}


		}
		int score = 0;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				score += board[i][j];
				//cout << board[i][j] << "\t";
			}
			//cout << endl;
			//cout << endl;
		}
		if (score > 0)
			answer = 2;
		else if (score == 0)
			answer = 0;
		else
			answer = 1;
		cout << answer << endl;

	}
}