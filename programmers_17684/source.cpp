#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dictation{ "","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q",
        "R","S","T","U","V","W","X","Y","Z" };
    unordered_map<string, int> dict;
    int new_idx = 26;
    for (int i = 1; i < dictation.size(); i++)
    {
        dict[dictation[i]] = i;
    }
    for (int i = 0; i < msg.size(); i++)
    {
        string current = "";
        current += msg[i];
        int idx;
        while (dict[current] > 0&&i<msg.size())
        {
            idx = dict[current];
            current += msg[++i];
        }
        i--;
        //cout << current << endl;
        answer.push_back(idx);
        dict[current] = ++new_idx;
    }
    return answer;
}

int main()
{
    solution("KAKAO");
}