#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(string a, string b)
{
    int size = a.size();
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), 0);
    queue<pair<string,int>> q;
    q.push(make_pair(begin,0));
    do
    {
        string tmp = q.front().first;
        int dis = q.front().second;
        q.pop();
        for (int i = 0; i < words.size(); i++)
        {
            if(!visited[i] && check(tmp, words[i]))
            {
                visited[i]=1;
                q.push(make_pair(words[i],dis+1));
                if (words[i] == target)
                    return dis + 1;
            }
        }
    } while (!q.empty());


    return answer;
}