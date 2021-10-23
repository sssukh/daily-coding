#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;



int solution(string dirs) {
    int answer = 0;
    vector<vector<int>> map(21, vector<int>(21, 0));
    int dirSize = dirs.size();
    int cur_x = 10;
    int cur_y = 10;
    for (int i = 0; i < dirSize; i++)
    {
        if (dirs[i] == 'U')
        {
            if (cur_y - 2 >=0)
            {
                cur_y--;
                if (map[cur_x][cur_y] == 0)
                {
                    map[cur_x][cur_y] =1;
                    answer++;
                }
                cur_y--;
            }
        }
        else if (dirs[i] == 'L')
        {
            if (cur_x - 2 >= 0)
            {
                cur_x--;
                if (map[cur_x][cur_y] == 0)
                {
                    map[cur_x][cur_y]=1;
                    answer++;
                }
                cur_x--;
            }
        }
        else if (dirs[i] == 'D')
        {
            if (cur_y + 2 <= 20)
            {
                cur_y++;
                if (map[cur_x][cur_y] == 0)
                {
                    map[cur_x][cur_y]=1;
                    answer++;
                }
                cur_y++;
            }
        }
        else
        {
            if (cur_x + 1 <= 20)
            {
                cur_x++;
                if (map[cur_x][cur_y] == 0)
                {
                    map[cur_x][cur_y] =1;
                    answer++;
                }
                cur_x++;
            }
        }
       
    }
    ;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map.size(); j++)
        {
            cout << map[i][j] << "\t";
        }
        cout << "\n\n\n\n";
    }

    return answer;
}

int main()
{
    string test = "ULURRDLLU";
    cout << solution(test);
}