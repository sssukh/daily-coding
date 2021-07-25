#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<int> stack;
    stack.push(0); //stack에 index값을 넣는다.
    int point=0;
    for (int i = 1; i < s.size(); i++)
    {
        cout << point << " " << i << endl;
        cout << s[point] << " " << s[i] << endl;
        if (stack.empty())
        {
            stack.push(i);
            point =i;

        }
        else if (s[point] != s[i])
        {
            stack.push(i);
            point = stack.top();
        }
        else
        {
            stack.pop();
            if (stack.empty())
            {
                continue;
            }
            point = stack.top();
        }
        
    }
    if (stack.empty())
    {
        answer = 1;
    }

    return answer;
}

int main()
{
    string test = "baabaa";
    cout << solution(test);
}