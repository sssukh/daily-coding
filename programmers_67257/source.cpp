#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression) { //아예 숫자와 op로 변환해서 벡터에 저장하자
    long long answer = 0;

    int exSize = expression.size();
    vector<string> ex;
    string tmp = "";
    vector<long long> nums;
    for (int i = 0; i < exSize; i++)
    {
        if (isdigit(expression[i]))
        {
            tmp += expression[i];
        }
        else
        {
            nums.push_back(stoi(tmp));
            tmp = expression[i];
            ex.push_back(tmp);
            tmp = "";
        }
    }
    nums.push_back(stoi(tmp));
    
   

    vector<string> oper={ "*","+","-"};
    vector<int> order = { 0,1,2 };
    do
    {
      
        vector<long long> cursur1 = nums;
        vector<long long> cursur2;
        vector<string> exp = ex;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < exp.size(); j++)
            {
                if (exp[j] == oper[order[i]])
                {
                    if (exp[j] == "*")
                    {
                        cursur1[j] = cursur1[j] * cursur1[j + 1];
                    }
                    else if (exp[j] == "+")
                    {
                        cursur1[j] = cursur1[j] + cursur1[j + 1];
                    }
                    else
                    {
                        cursur1[j] = cursur1[j] - cursur1[j+1];
                    }
                    cursur1.erase(cursur1.begin() + j + 1);
                    exp.erase(exp.begin() + j);
                    j--;
                }
            }
            for (long long l : cursur1)
                cout << l << " ";
            cout << endl;
        }
        //cout << cursur1.back() << " " << cursur1.size() << endl;
        if (answer < abs(cursur1.back()))
            answer = abs(cursur1.back());

    } while (next_permutation(order.begin(), order.end()));
    

    return answer;
}


int main()
{
    string test = "50*6-3*2";
    cout<<solution(test)<<endl;
}