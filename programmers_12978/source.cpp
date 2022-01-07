#include <iostream>
#include <vector>
using namespace std;

#define INF 1e8

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<int>> map(N + 1, vector<int>(N + 1, INF));
    for (int i = 0; i < road.size(); i++)
    {
        if (road[i][2] < map[road[i][0]][road[i][1]])
        {
            map[road[i][0]][road[i][1]] = road[i][2];
            map[road[i][1]][road[i][0]] = road[i][2];
        }

    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                map[i][j] =0;
        }
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (map[1][i] <= K)
        {
            answer++;
        }
    }
    return answer;
}