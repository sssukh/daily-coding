#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{ 0,0 };//¹øÈ£,Â÷·Ê

    vector<int> people(n, 0); // Â÷·ÊÀúÀå
    unordered_map<string, int> count;
    for (int i = 0; i < words.size(); i++)
    {
        people[i % n]++;
        if (count[words[i]] > 0)
        {
            answer[0] = i % n + 1;
            answer[1] = people[i % n];
            break;
        }
        if (i > 0 && words[i - 1].back() != words[i][0])
        {
            answer[0] = i % n + 1;
            answer[1] = people[i % n];
            break;
        }
        count[words[i]]++;
    }

    return answer;
}