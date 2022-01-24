#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

#define INF 1e8

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    queue<vector<int>> q; //row좌표, col좌표, 방향(1 : 오른쪽, 2 : 아래쪽, 4 : 왼쪽, 8 : 위쪽)
    vector<pair<int, int>> directions = { {1,0},{-1,0},{0,1},{0,-1} };
    q.push({ size - 1,size - 1,15,0 });
    vector<vector<vector<int>>> visited(board.size(), vector<vector<int>>(board.size(), vector<int>(4, 0)));
    do
    {
        vector<int> tmp = q.front();
        q.pop();
        if (tmp[0] < board.size() && tmp[0] >= 0 && tmp[1] < board.size() && tmp[1] >= 0 && board[tmp[0]][tmp[1]] != 1)
        {
            if (visited[tmp[0]][tmp[1]][log(tmp[2])] == 0 || visited[tmp[0]][tmp[1]][log(tmp[2])] >= tmp[3])
            {
                visited[tmp[0]][tmp[1]][log(tmp[2])] = tmp[3];

                //board[tmp[0]][tmp[1]] = tmp[3];
                q.push({ tmp[0] + 1,tmp[1],2,tmp[3] + (tmp[2] & 2 ? 100 : 600) });
                q.push({ tmp[0] - 1,tmp[1],8,tmp[3] + (tmp[2] & 8 ? 100 : 600) });
                q.push({ tmp[0],tmp[1] + 1,1,tmp[3] + (tmp[2] & 1 ? 100 : 600) });
                q.push({ tmp[0],tmp[1] - 1,4,tmp[3] + (tmp[2] & 4 ? 100 : 600) });
            }
        }
    } while (!q.empty());

    answer = INF;
    for (int i = 0; i < 4; i++)
    {
        if (visited[0][0][i] != 0 &&  visited[0][0][i] < answer)
        {
            answer = visited[0][0][i];
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            for (int k = 0; k < 4; k++)
                cout << visited[i][j][k] << " ";
            cout << "\t";
        }
        cout << endl;
    }

    return answer;
}

int main()
{
    vector<vector<int>> test = { {0,0,0} ,{0,0,0} ,{0,0,0} };
    vector<vector<int>> test1 = { {0,0,0,0,0,0,0,1} ,{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0} };
    cout<<solution(test1);
}