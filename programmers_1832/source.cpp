#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

void DFS(int row, int col, vector<vector<int>>& city_map, int& answer, bool fromLeft)
{
    
    if (row >= city_map.size() || col >= city_map[0].size() || city_map[row][col] == 1)
        return;
    if (row == city_map.size() - 1 && col == city_map[0].size() - 1)
        answer = (answer + 1) % MOD;
    //cout << "row : " << row << " col : " << col << endl;
    if (city_map[row][col] == 0)
    {
        DFS(row + 1, col, city_map, answer, 0);
        DFS(row, col + 1, city_map, answer, 1);
    }
    else
    {
        if (fromLeft)
        {
            DFS(row, col + 1, city_map, answer, 1);
        }
        else
        {
            DFS(row + 1, col, city_map, answer, 0);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) 
{
    int answer = 0;
    
    //DFS(0, 0, city_map, answer, 1);
    //cout << answer << endl;

    vector<vector<vector<int>>> counts(m, vector<vector<int>>(n, vector<int>({ 0,0 })));    //위에서 옴, 왼쪽에서 옴
    //counts[0][0] = { 1,1 };
    for (int row = 1; row < m; row++)
    {
        if (city_map[row][0] == 1)
        {
            break;
        }
        counts[row][0][0] = 1;
    }
    for (int col = 1; col < n; col++)
    {
        if (city_map[0][col] == 1)
        {
            break;
        }
        counts[0][col][1] = 1;
    }
    for (int row = 1; row < m; row++)
    {
        for (int col = 1; col < n; col++)
        {
            if (city_map[row - 1][col] == 2)
            {
                counts[row][col][0] = (counts[row][col][0]+counts[row - 1][col][0])%MOD;
            }
            else if (city_map[row - 1][col] == 0)
            {
                counts[row][col][0] =(counts[row][col][0]+counts[row - 1][col][0]) % MOD;
                counts[row][col][0] =(counts[row][col][0]+counts[row - 1][col][1]) % MOD;
            }

            if (city_map[row][col - 1] == 2)
            {
                counts[row][col][1] =(counts[row][col][1]+counts[row][col - 1][1]) % MOD;
            }
            else if (city_map[row][col - 1] == 0)
            {
                counts[row][col][1] =(counts[row][col][1]+counts[row][col - 1][0]) % MOD;
                counts[row][col][1] =(counts[row][col][1]+counts[row][col - 1][1]) % MOD;
            }


            /*
            if (row - 1 >= 0)
            {
                if (city_map[row][col] == 0)
                {
                    counts[row][col][0] += counts[row - 1][col][0];
                    counts[row][col][0] += counts[row - 1][col][1];
                }
                else if (city_map[row][col] == 2)
                {
                    counts[row][col][0] += counts[row - 1][col][0];
                }
            }
            if (col - 1 >= 0)
            {
                if (city_map[row][col] == 0)
                {
                    counts[row][col][1] += counts[row][col - 1][0];
                    counts[row][col][1] += counts[row][col - 1][1];
                }
                else if (city_map[row][col] == 2)
                {
                    counts[row][col][1] += counts[row][col - 1][1];
                }
            }
            */
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << counts[i][j][0] << " " << counts[i][j][1] << "\t";
        }
        cout << endl;
    }
    answer = (counts[m - 1][n - 1][0] + counts[m - 1][n - 1][1])%MOD;
    cout << answer << endl;
    return answer;
}

int main()
{
    vector<vector<int>> test1 = { {0, 0, 0} ,{0, 0, 0},{0, 0, 0} };
    solution(3, 3, test1);
}