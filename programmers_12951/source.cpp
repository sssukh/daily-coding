#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    if (!isdigit(s[0]))
    {
        answer += (char)toupper(s[0]);
    }
    else
        answer += s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            answer += s[i];
        else
            answer += (char)tolower(s[i]);
        if (s[i-1] == ' '&&!isdigit(s[i]))
        {
                answer[i] = (char)toupper(s[i]);
        }
       
    }
    return answer;
}