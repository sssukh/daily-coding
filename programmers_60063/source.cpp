#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct pos
{
    int row1, col1, row2, col2, count;
};

void insertValue(int row, int col, int value, vector<vector<vector<int>>>& board, bool isVertical)
{
    if (board[row][col][isVertical] == 0)
        board[row][col][isVertical] = value;
    else
    {
        board[row][col][isVertical] = max(board[row][col][isVertical], value);
    }
}



int solution(vector<vector<int>> board)
{
    int answer = 10000;
    int size = board.size();
    queue<pos> q;
    vector<vector<vector<int>>> robot_on_board(size, vector<vector<int>>(size, { 0,0 }));
    q.push({ 0,0,0,1,0 });
    while (!q.empty())
    {
        pos current = q.front();
        q.pop();
        if (current.row1 < size && current.row1 >= 0 && current.col1 < size && current.col1 >= 0 &&
            board[current.row1][current.col1] != 1&& current.row2 < size && current.row2 >= 0 &&
            current.col2 < size && current.col2 >= 0 && board[current.row2][current.col2] != 1)
        {
            bool isVertical;
            if (current.col1 == current.col2)
                isVertical = 1;
            else
                isVertical = 0;
            if (robot_on_board[current.row1][current.col1][isVertical] == 0 || 
                robot_on_board[current.row2][current.col2][isVertical] == 0 ||
                robot_on_board[current.row1][current.col1][isVertical] < current.count ||
                robot_on_board[current.row2][current.col2][isVertical] < current.count)
            {
                
                insertValue(current.row1, current.col1, current.count, robot_on_board,isVertical);
                insertValue(current.row2, current.col2, current.count, robot_on_board,isVertical);
                q.push({ current.row1 + 1, current.col1, current.row2 + 1, current.col2, current.count - 1 });
                q.push({ current.row1 - 1, current.col1, current.row2 - 1, current.col2, current.count - 1 });
                q.push({ current.row1, current.col1 + 1, current.row2, current.col2 + 1, current.count - 1 });
                q.push({ current.row1, current.col1 - 1, current.row2, current.col2 - 1, current.count - 1 });

                if (isVertical)
                {
                    if (current.col1 - 1 >= 0 && board[current.row1][current.col1 - 1] != 1)
                    {
                        q.push({ current.row2, current.col1 - 1, current.row2, current.col2, current.count - 1 });
                    }
                    if (current.col1 + 1 < size && board[current.row1][current.col1 + 1] != 1)
                    {
                        q.push({ current.row2, current.col1 + 1, current.row2, current.col2, current.count - 1 });
                    }
                    if (current.col2 - 1 >= 0 && board[current.row2][current.col2 - 1] != 1)
                    {
                        q.push({ current.row1, current.col1, current.row1, current.col2 - 1, current.count - 1 });
                    }
                    if (current.col2 + 1 < size && board[current.row2][current.col2 + 1] != 1)
                    {
                        q.push({ current.row1, current.col1, current.row1, current.col2 + 1, current.count - 1 });
                    }
                }
                else
                {
                    if (current.row1 - 1 >= 0 && board[current.row1 - 1][current.col1] != 1)
                    {
                        q.push({ current.row1 - 1, current.col2, current.row2, current.col2, current.count - 1 });
                    }
                    if (current.row1 + 1 < size && board[current.row1 + 1][current.col1] != 1)
                    {
                        q.push({ current.row1 + 1, current.col2, current.row2, current.col2, current.count - 1 });
                    }
                    if (current.row2 - 1 >= 0 && board[current.row2 - 1][current.col2] != 1)
                    {
                        q.push({ current.row1, current.col1, current.row2 - 1, current.col1, current.count - 1 });
                    }
                    if (current.row2 + 1 < size && board[current.row2 + 1][current.col2] != 1)
                    {
                        q.push({ current.row1, current.col1, current.row2 + 1, current.col1, current.count - 1 });
                    }
                }

            }

            if (robot_on_board[size - 1][size - 1][0] < 0)
            {
                //answer = min(answer, -board[size - 1][size - 1]);
                return -robot_on_board[size - 1][size - 1][0];
            }
            if (robot_on_board[size - 1][size - 1][1] < 0)
            {
                //answer = min(answer, -board[size - 1][size - 1]);
                return -robot_on_board[size - 1][size - 1][1];
            }
        }
    }
    /*
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << "\n\n";
    }
    */
    return answer;
}