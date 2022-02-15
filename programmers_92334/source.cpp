#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(),0);
    unordered_map<string, unordered_set<string>> reports;
    unordered_map<string, int> idx_for_id;
    for (int i = 0; i < id_list.size(); i++)
    {
        idx_for_id[id_list[i]] = i;
    }
    for (int i = 0; i < report.size(); i++)
    {
        istringstream input(report[i]);
        string reporter;
        string reported;
        input >> reporter >> reported;
        reports[reported].insert(reporter);
    }

    for (auto reported_user = reports.begin(); reported_user != reports.end(); reported_user++)
    {
        if (reported_user->second.size() >= k)
        {
            for (auto report_users = reported_user->second.begin(); report_users != reported_user->second.end(); report_users++)
            {
                answer[idx_for_id[*report_users]]++;
            }
        }
    }

    return answer;
}

