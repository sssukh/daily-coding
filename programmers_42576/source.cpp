#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> list;
    for (auto i : participant)
        list[i]++;
    for (auto i : completion)
        list[i]--;
    for (auto i : list)
    {
        if (i.second > 0)
        {
            answer = i.first;
            break;
        }
    }

    return answer;
}