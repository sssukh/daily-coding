#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int BFS(vector<vector<int>> board, int row, int col, int dir)
{
    queue<vector<int>> q;  //row좌표, col좌표, 방향(1 : 오른쪽, 2 : 아래쪽, 4 : 왼쪽, 8 : 위쪽)
    q.push({ row, col, dir, 100 });
    do
    {
        vector<int> tmp = q.front();
        q.pop();
        
        if (tmp[0] < board.size() && tmp[0] >= 0 && tmp[1] < board.size() && tmp[1] >= 0 && board[tmp[0]][tmp[1]] != 1)
        {
            if (board[tmp[0]][tmp[1]] == 0)
            {
                board[tmp[0]][tmp[1]] = tmp[3];
                q.push({ tmp[0] + 1,tmp[1],2,tmp[3] + (tmp[2] & 2 ? 100 : 600) });
                q.push({ tmp[0] - 1,tmp[1],8,tmp[3] + (tmp[2] & 8 ? 100 : 600) });
                q.push({ tmp[0],tmp[1] + 1,1,tmp[3] + (tmp[2] & 1 ? 100 : 600) });
                q.push({ tmp[0],tmp[1] - 1,4,tmp[3] + (tmp[2] & 4 ? 100 : 600) });
            }
            else if (board[tmp[0]][tmp[1]] >= tmp[3])
            {
                board[tmp[0]][tmp[1]] = tmp[3];
                q.push({ tmp[0] + 1,tmp[1],2,tmp[3] + (tmp[2] & 2 ? 100 : 600) });
                q.push({ tmp[0] - 1,tmp[1],8,tmp[3] + (tmp[2] & 8 ? 100 : 600) });
                q.push({ tmp[0],tmp[1] + 1,1,tmp[3] + (tmp[2] & 1 ? 100 : 600) });
                q.push({ tmp[0],tmp[1] - 1,4,tmp[3] + (tmp[2] & 4 ? 100 : 600) });
            }
        }
    } while (!q.empty());

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }

    return board[board.size() - 1][board.size() - 1];
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = min(BFS(board, 0, 1, 1), BFS(board, 1, 0, 2));

   

   
    return answer;
}

int main()
{
    vector<vector<int>> test = { {0,0,0} ,{0,0,0} ,{0,0,0} };
    vector<vector<int>> test1 = { {0,0,0,0,0,0,0,1} ,{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0} };
    cout<<solution(test1);
}