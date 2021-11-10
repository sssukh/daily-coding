#include <string>
#include <vector>
#include <iostream>

using namespace std;

void check(int m, int n, vector<vector<string>>& game,vector<pair<int,int>>& list)
{
    string tmp = game[m][n];
    if (tmp!="\0"&&game[m + 1][n] == tmp && game[m][n + 1] == tmp && game[m + 1][n + 1] == tmp)
    {
        list.push_back(make_pair(m, n));
        //cout << n << " " << m << endl;
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;

    vector<vector<string>> game(n, vector<string>(m, ""));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            game[i][j] = board[j][i];
        }
    }
    while (true)
    {
        vector<pair<int, int>> list;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < m-1; j++)
            {
                check(i, j, game, list);
            }
        }
        if (list.empty())
            break;
        
        for (pair<int, int> p : list) //Áö¿ì±â
        {
            game[p.first][p.second] = "\0";
            game[p.first+1][p.second+1] = "\0";
            game[p.first+1][p.second] = "\0";
            game[p.first][p.second+1] = "\0";
        }
        
        

        for (int i = 0; i < n; i++)
        {
            for (int j=0;j<game[i].size();j++)
            {
                if (game[i][j] == "\0")
                {
                    game[i].erase(game[i].begin() + j);
                    j--;
                }
            }
            while (game[i].size() < m)
            {
                game[i].insert(game[i].begin(), "\0");
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (game[i][j] == "\0")
                answer++;
            //cout << game[i][j] << "\t";
        }
        //cout << endl;
    }
    return answer;
}


int main()
{
    vector<string> test = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    cout<<solution(6, 6, test)<<endl;
}