#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int count = 0;
    int zeros = 0;

    while (s != "1")
    {
        cout << s << endl;
        string tmp = "";
        for (char c : s)
        {
            if (c == '0')
            {
                zeros++;
            }
            else
            {
                tmp += c;
            }
        }
        int size = tmp.size();
        tmp = "";
        while (size != 0)
        {
            int res = size % 2;
            tmp += to_string(res);
            size /= 2;
        }
        s = "";
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            s += tmp[i];
        }
        count++;
    }

    return { count,zeros };
}

int main()
{
    solution("01110");
}