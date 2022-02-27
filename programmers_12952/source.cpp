#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isQueenExist(int row, int col, vector<pair<int, int>>& queens)
{
    for (int i = 0; i < queens.size(); i++)
    {
        if (queens[i].second == col||abs(queens[i].first-row)==abs(queens[i].second-col))
            return true;
    }
    return false;
}

void DFS(int row, int col, vector<pair<int, int>>& queens,int n,int& answer)
{
    if (isQueenExist(row, col, queens))
        return;
    queens.push_back({ row,col });
    if (queens.size()==n)
    {
        ++answer;
        queens.pop_back();
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        DFS(row + 1, i, queens, n, answer);
    }
    queens.pop_back();
}
int solution(int n) 
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> queens;
        DFS(0, i, queens, n, answer);
    }
    return answer;
}