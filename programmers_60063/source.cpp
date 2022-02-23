#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct pos
{
    int row1, col1, row2, col2, count;
};

void insertValue(int row, int col, int value, vector<vector<int>>& board)
{
    if (board[row][col] == 0)
        board[row][col] = value;
    else
    {
        board[row][col] = max(board[row][col], value);
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 10000;
    int size = board.size();
    queue<pos> q;
    q.push({ 0,0,0,1,0 });
    while (!q.empty())
    {
        pos current = q.front();
        q.pop();
        if (current.row1 < size && current.row1 >= 0 && current.col1 < size && current.col1 >= 0 &&
            board[current.row1][current.col1] != 1&& current.row2 < size && current.row2 >= 0 &&
            current.col2 < size && current.col2 >= 0 && board[current.row2][current.col2] != 1)
        {
            if ((board[current.row1][current.col1] == 0&& board[current.row2][current.col2] == 0) ||
                board[current.row1][current.col1] < current.count|| board[current.row2][current.col2] < current.count)
            {
                insertValue(current.row1, current.col1, current.count, board);
                insertValue(current.row2, current.col2, current.count, board);

               

            }

            if (board[size - 1][size - 1] < 0)
            {
                answer = min(answer, -board[size - 1][size - 1]);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << "\n\n";
    }

    return answer;
}