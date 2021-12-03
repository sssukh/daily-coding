#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    vector<int> connected(n, 0);
    connected[0] = 0;
    int count = 1;
    int current_island = 0;
    vector<vector<int>> map(n, vector<int>(n, 0));
    for (int i = 0; i < costs.size(); i++)
    {
        map[costs[i][0]][costs[i][1]] = costs[i][2];
        map[costs[i][1]][costs[i][0]] = costs[i][2];
    }

    while (count < n)
    {
        pair<int, int> min = { -1,-1 }; //value, idx
        for (int i = 0; i < n; i++)
        {
            int tmp;
            if ((tmp=map[current_island][i])>0&&!connected[i])
            {
                if (min.first > -1 && tmp < min.first)
                {
                    min.second = i;
                    min.first = tmp;
                }
                else if (min.first == -1)
                {
                    min.first = tmp;
                    min.second = i;
                }
                
            }
        }
        if (min.first != -1)
        {
            if (connected[current_island] > min.first || connected[min.second] > 0)
                connected[current_island] = min.first;
            current_island = min.second;
            connected[min.second] = min.first;
            count++;
        }

    }
    for (int i = 0; i < n; i++)
    {
        answer += connected[i];
        cout << connected[i] << endl;
    }
    return answer;
}