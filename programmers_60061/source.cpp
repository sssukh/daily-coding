#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool getWall(int x, int y, bool thing, vector<vector<vector<bool>>>& wall)
{
    if (x < 0 || y < 0 || x >= wall.size() || y >= wall.size())
        return false;
    return wall[x][y][thing];
}

bool check(int x, int y, vector<vector<vector<bool>>>& wall, bool thing)
{
 //   cout << x << " " << y <<" "<<thing<< endl;
   
    // thing : 0�� ��, 1�� ���
    if (thing)
    {
        if (y==0||getWall(x,y,0,wall) || getWall(x-1,y,0,wall)|| getWall(x,y-1,1,wall))
            return true;
        else
            return false;
    }
    else
    {
        if ((getWall(x+1,y,0,wall) && getWall(x-1,y,0,wall)) || getWall(x,y-1,1,wall) || getWall(x+1,y-1,1,wall))
            return true;
        else
            return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    vector<vector<vector<bool>>> wall(n+2, vector<vector<bool>>(n+2, vector<bool>(2, 0))); // 0 : �� , 1 : ���
    int size = build_frame.size();
    for (int i = 0; i < size; i++)
    {
        vector<int> tmp = build_frame[i];
        if (tmp[2])     //��
        {
            if (tmp[3]) //��ġ
            {
                /*
                if (tmp[0]<n&&tmp[1]>0&&(wall[tmp[0]+1][tmp[1]-1][1]||wall[tmp[0]][tmp[1]-1][1])
                    ||(wall[tmp[0]-1][tmp[1]][0]&&wall[tmp[0]+1][tmp[1]][0]))
                {
                    wall[tmp[0]][tmp[1]][0] = 1;
                }
                */
                if(check(tmp[0],tmp[1],wall,0))
                    wall[tmp[0]][tmp[1]][0] = 1;
            }
            else        //����
            {
                // �� �Ʒ��� ����� �����鼭 ����,�������� ���� �ְų� ����� �ִٸ� ���� �Ұ���
                // ���� ���� �����鼭 
                wall[tmp[0]][tmp[1]][0] = 0;
                if (check(tmp[0], tmp[1], wall, 1) && check(tmp[0] + 1, tmp[1], wall, 1) &&
                    check(tmp[0] - 1, tmp[1], wall, 0) && check(tmp[0] + 1, tmp[1], wall, 0))
                    wall[tmp[0]][tmp[1]][0] = 0;
                else
                    wall[tmp[0]][tmp[1]][0] = 1;
            }
        }
        else            //���
        {
            if (tmp[3]) //��ġ
            {
               /*
                if (tmp[1] > 0 && (wall[tmp[0]][tmp[1] - 1][1] == 0
                    && (wall[tmp[0] - 1][tmp[1]][0] == 0 && wall[tmp[0]][tmp[1]][0] == 0)))
                        continue;
                        */
                if(check(tmp[0],tmp[1],wall,1))
                    wall[tmp[0]][tmp[1]][1] = 1;
            }
            else        //����
            {
                //���ʿ� ���� �� �� ������ ���� ����, ���ʿ��� ���� �����鼭 ���� ��ġ�� ����� ������ ��������
                wall[tmp[0]][tmp[1]][1] = 0;
                if (check(tmp[0] - 1, tmp[1] + 1, wall, 0) && check(tmp[0], tmp[1] + 1, wall, 0) &&
                    check(tmp[0], tmp[1] + 1, wall, 1))
                    wall[tmp[0]][tmp[1]][1] = 0;
                else
                    wall[tmp[0]][tmp[1]][1] = 1;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (wall[i][j][1])
                answer.push_back({ i,j,0 });
            if (wall[i][j][0])
                answer.push_back({ i,j,1 });
        }
    }

    return answer;
}


int main()
{
    vector<vector<int>> test = { {0, 0, 0, 1},{2, 0, 0, 1},{4, 0, 0, 1},{0, 1, 1, 1},{1, 1, 1, 1},
        {2, 1, 1, 1},{3, 1, 1, 1},{2, 0, 0, 0},{1, 1, 1, 0},{2, 2, 0, 1} };
    solution(5, test);
}
