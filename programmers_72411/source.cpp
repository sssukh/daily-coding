#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool compare(string a, string b)
{
    return a < b;
}


bool cmp(char a, char b) 
{
    return a < b;
}

bool comp(pair<string, int> a, pair<string, int> b)
{
    
        return a.second < b.second;
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int orderSize = orders.size();
    unordered_map<string, int> courses;
    vector<pair<string, int>> common_menu;
    for (int i = 0; i < orderSize; i++)
    {
        string find_common = orders[i];
        int sSize = find_common.size();
        if (sSize < 2)
            continue;
            sort(find_common.begin(), find_common.end(),cmp);
            courses[find_common]++;
           
            for (int k = 2; k < sSize; k++)
            {
                vector<bool>v(sSize - k, false);
                v.insert(v.end(), k, true);
                do
                {
                    string sub = "";
                    for (int l = 0; l < sSize; l++)
                    {
                        if (v[l])
                            sub += find_common[l];
                    }
                    courses[sub]++;
                } while (next_permutation(v.begin(), v.end()));
            }
       
    }

    for (auto iter = courses.begin(); iter != courses.end(); iter++)
    {
        if (iter->second > 1)
        {
            pair<string, int> tmp = make_pair(iter->first, iter->second);
            common_menu.push_back(tmp);
        }
    
    }
    sort(common_menu.begin(), common_menu.end(),comp);
    vector<int> course_max(course.size(), 0);
    while (!common_menu.empty())
    {
        string temp = common_menu.back().first;
        int max = common_menu.back().second;
        common_menu.pop_back();
        for (int i = 0; i < course.size(); i++)
        {
            if (course[i] == temp.size())
            {
                //cout << temp << " " << max << " " << course_max[i] <<" "<<i << endl;
                if (course_max[i] <= max)
                {
                    course_max[i] = max;
                    answer.push_back(temp);
                }
                break;
            }
        }

    }
    sort(answer.begin(), answer.end(),compare);
    
    for (string s : answer)
    {
        cout << s << "\t";
    }
    cout << endl;
    
    return answer;
}

int main()
{
    vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course = { 2,3,5 };
    solution(orders, course);
}