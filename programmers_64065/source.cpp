#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> check;
    vector<vector<int>> organized;
    int sSize = s.size();
    string cur = "";
    for (int i = 1; i < sSize-1; i++)
    {
        
        if (s[i] == '{')
        {
            vector<int> tmp;
            organized.push_back(tmp);

        }
        else if (s[i]==',')
        {
            organized.back().push_back(stoi(cur));
            cur = "";
        }
        else if (s[i] == '}')
        {
            organized.back().push_back(stoi(cur));
            cur = "";
            i++;
        }
        else
        {
            cur += s[i];
        }
    }
    sort(organized.begin(), organized.end(), cmp);
    for (vector<int> v : organized)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (check[v[i]] == 0)
            {
                check[v[i]]++;
                answer.push_back(v[i]);
                break;
            }
        }
    }

    return answer;
}

int main()
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}