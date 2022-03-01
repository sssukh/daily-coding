#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    string answer="";
    list<bool> table(n,1);
 
    int current = k;
    vector<int> removes;
    for (int i = 0; i < cmd.size(); i++)
    {
        //cout << k << endl;
        string command = cmd[i];
        if (command[0] == 'U')
        {
            int value = stoi(command.substr(2, command.size() - 2));
            k -= value;
        }
        else if (command[0] == 'D')
        {
            int value = stoi(command.substr(2, command.size() - 2));
            k += value;
        }
        else if (command[0] == 'C')
        {
            removes.push_back(k);
            auto iter = table.begin();
            for (int j = 0; j < k; j++)
            {
                iter++;
            }
            table.erase(iter);
            if (k == table.size())
                --k;
        }
        else
        {
            int tmp = removes.back();
            removes.pop_back();
            auto iter = table.begin();
            for (int j = 0; j < k; j++)
            {
                iter++;
            }
            table.insert(iter,1);
            if (k >= tmp)
                ++k;
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        answer += "O";
    }

    for (int i : removes)
    {
        answer[i] = 'X';
    }
    */
    
    while (!removes.empty())
    {
        int tmp = removes.back();
        removes.pop_back();
        auto iter = table.begin();
        for (int j = 0; j < tmp; j++)
        {
            iter++;
        }
        table.insert(iter, 0);
    }
    for (bool i : table)
    {
        if (i)
            answer += "O";
        else
            answer += "X";
    }

    

    return answer;
}