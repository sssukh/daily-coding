#include <string>
#include <vector>

using namespace std;


string solution(string p) {
    if (p == "")
        return p;
    string answer = "";
    int pSize = p.size();
    int count = 0;
    int idx = 0;
    string tmp = "";
    bool check = true;
    do ///»Æ¿Œ
    {
        tmp += p[idx];
        if (tmp.back() == '(')
            count++;
        else
            count--;
        if (count < 0)
            check = false;

        idx++;

        if (count == 0)
        {
            if (check)
                answer += tmp + solution(p.substr(idx, pSize - idx));
            else
            {
                answer += "(" + solution(p.substr(idx, pSize - idx)) + ")";
                for (int i = 1; i<tmp.size()-1; i++)
                {
                    if (tmp[i] == '(')
                        answer += ')';
                    else
                        answer += '(';
                }
            }
        }
    } while (count != 0);

    return answer;
}