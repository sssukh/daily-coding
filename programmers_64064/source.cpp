#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> compare(vector<string>& user_id, string banned_id)
{
    vector<int> result(user_id.size(),0);
    for (int i = 0; i < user_id.size(); i++)
    {
        if (user_id[i].size() != banned_id.size())
            continue;
        int j;
        for (j = 0; j < banned_id.size(); j++)
        {
            if (banned_id[j] == '*')
                continue;
            if (banned_id[j] != user_id[i][j])
                break;
        }
        if (j == banned_id.size())
            result[i] = 1;
    }
    return result;
}

void get_list(vector<vector<int>>& banned_list,int idx, vector<int>& list,vector<vector<int>>& case_of_banned_list)
{
    if (idx == banned_list.size())
    {


        for (int i = 0; i < list.size(); i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;

        vector<int> sorted_list = list;
        sort(sorted_list.begin(), sorted_list.end());
        bool is_exist = false;
        for (int i = 0; i < case_of_banned_list.size(); i++)
        {
            int j;
            for (j = 0; j < case_of_banned_list[i].size(); j++)
            {
                if (case_of_banned_list[i][j] != sorted_list[j])
                    break;
            }
            if (j == case_of_banned_list[i].size())
            {
                is_exist = true;
                break;
            }
        }
        if (!is_exist)
        {
            case_of_banned_list.push_back(sorted_list);
        }
        return;
    }
    for (int i = 0; i < banned_list[idx].size(); i++)
    {
        if (banned_list[idx][i])
        {
            int j;
            for (j = 0; j < list.size(); j++)
            {
                if (list[j] == i)
                    break;
            }
            if (j == list.size())
                list.push_back(i);
            else
                continue;
            get_list(banned_list, idx + 1, list, case_of_banned_list);
            list.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    int answer = 0;
    vector<vector<int>> banned_list;
    vector<vector<int>> case_of_banned_list;
    for (int i = 0; i < banned_id.size(); i++)
    {
        banned_list.push_back(compare(user_id, banned_id[i]));
    }
    for (int i = 0; i < banned_list.size(); i++)
    {
        for (int j = 0; j < banned_list[i].size(); j++)
            cout << banned_list[i][j] << " ";
        cout << endl;
    }
    vector<int> list;
    get_list(banned_list, 0, list, case_of_banned_list);
    
    return case_of_banned_list.size();
}