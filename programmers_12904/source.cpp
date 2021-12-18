#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 0;

    int size = s.size();
    for (int current_size = size; current_size >= 1; current_size--)
    {
        for (int start_idx = 0; start_idx + current_size <= size; start_idx++)
        {
            //string tmp = s.substr(start_idx, current_size);
            int i;
            cout << current_size << endl;
            for (i = start_idx; i <= current_size/2 + start_idx; i++)
            {
                if (s[i] != s[2*start_idx + current_size - 1 - i])
                    break;
            }
            if (i > current_size / 2 + start_idx)
                return current_size;
        }

    }


    return answer;
}