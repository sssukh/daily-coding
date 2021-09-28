#include<string>


using namespace std;

bool solution(string s)
{
    bool answer = true;
    int stat = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stat++;
        else
            stat--;
        if (stat < 0)
            return false;
    }
   
    return stat==0?answer:false;
}