#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> check;
    int str1Size = str1.size();
    int str2Size = str2.size();
    int total = 0;
    for (int i = 1; i < str1Size; i++)
    {
        char tmp1 = str1[i - 1];
        char tmp2 = str1[i];
        string tmp = "";
       

        if (((tmp1 >= 'a' && tmp1 <= 'z')||(tmp1>='A'&&tmp1<='Z')) 
            && ((tmp2 >= 'a' && tmp2 <= 'z') || (tmp2 >= 'A' && tmp2 <= 'Z')))
        {
            tmp += tolower(tmp1);
            tmp += tolower(tmp2);
            check[tmp]++;
            total++;
           
        }

    }

    for (int i = 1; i < str2.size(); i++)
    {
        char tmp1 = str2[i - 1];
        char tmp2 = str2[i];
        if (((tmp1 >= 'a' && tmp1 <= 'z') || (tmp1 >= 'A' && tmp1 <= 'Z'))
            && ((tmp2 >= 'a' && tmp2 <= 'z') || (tmp2 >= 'A' && tmp2 <= 'Z')))
        {
            string tmp = "";
            tmp += tolower(tmp1);
            tmp += tolower(tmp2);
            if (check[tmp] > 0)
            {
                check[tmp]--;
                answer++;
            }
            else
                total++;
            
            
        }
    }
    if (total != 0)
        answer = answer * 65536 / total;
    else
        answer = 65536;

    return answer;
}

int main()
{
    cout << solution("france", "french") << endl;;
}