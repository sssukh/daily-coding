#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    string answer="";
    vector<int> removes;// 제거한 표 저장
    vector<vector<int>> table(n,vector<int>(3,1)); //0 : 존재 유무, 1: 이전, 2 : 이후
    for (int i = 0; i < n; i++)
    {
        table[i][1] = i - 1;
        table[i][2] = i + 1;
    }

    for (int i = 0; i < cmd.size(); i++)
    {
        string current = cmd[i];
        if (current[0] == 'U')
        {
            int value = stoi(current.substr(2, current.size() - 2));
            for (int rep = 0; rep < value; rep++)
            {
                k = table[k][1];
            }
        }
        else if (current[0] == 'D')
        {
            int value = stoi(current.substr(2, current.size() - 2));
            for (int rep = 0; rep < value; rep++)
            {
                k = table[k][2];
            }
        }
        else if (current[0]=='C')
        {
            table[k][0] = 0;
            removes.push_back(k);
            if (table[k][2] == n)// 맨 뒤
            {
                table[table[k][1]][2] = n;
                k = table[k][1];
                
            }
            else if (table[k][1] == -1)// 맨 앞
            {
                table[table[k][2]][1] = -1;
                k = table[k][2];
            }
            else
            {
                table[table[k][1]][2] = table[k][2];
                table[table[k][2]][1] = table[k][1];
                k = table[k][2];
            }
        }
        else
        {
            int tmp = removes.back();
            removes.pop_back();
            table[tmp][0] = 1;
            if (table[tmp][2] == n)
            {
                table[table[tmp][1]][2] = tmp;
            }
            else if (table[tmp][1] == -1)
            {
                table[table[tmp][2]][1] = tmp;
            }
            else
            {
                table[table[tmp][1]][2] = tmp;
                table[table[tmp][2]][1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        answer += "O";
    }
    for (int i = 0; i < removes.size(); i++)
    {
        answer[removes[i]] = 'X';
    }
    return answer;
}

int main()
{
    vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
    
    cout << solution(8, 2, cmd);
}