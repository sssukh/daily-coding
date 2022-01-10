#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

vector<int> solution(vector<string> grid)
{
    vector<pair<int, int>> directions{ {0,1},{1,0},{0,-1},{-1,0} };
    int height = grid.size();
    int width = grid[0].size();
    vector<int> answer;
    vector<vector<vector<bool>>> map(height, vector<vector<bool>>(width, { 0,0,0,0 }));
    for (int i = 0; i < 4; i++)
    {
        int current_dir = i;
        for (int j = 0; j < height; j++)
        {
            for (int k = 0; k < width; k++)
            {
                pair<int, int> current_pos = { j,k };
                int distance = 0;
                while (true)
                {
                    if (map[current_pos.first][current_pos.second][current_dir])
                    {
                        break;
                    }
                    map[current_pos.first][current_pos.second][current_dir] = 1;
                    distance++;
                    current_pos = { (current_pos.first + directions[current_dir].first + height) % height,
                        (current_pos.second + directions[current_dir].second + width) % width };

                    if (grid[current_pos.first][current_pos.second] == 'R')
                    {
                        current_dir = (current_dir + 1) % 4;
                    }
                    else if (grid[current_pos.first][current_pos.second] == 'L')
                    {
                        current_dir = (current_dir + 3) % 4;
                    }
                }
                if (distance > 0)
                    answer.push_back(distance);
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}

   