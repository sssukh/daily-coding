#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> q1; //최소값 찾기  min heap
    priority_queue<int, vector<int>, less<int>> q2; //최대값 찾기   max heap
    unordered_map<int, int> hash;
    int qsize = 0;
    for (string v : operations)
    {
        if (v[0] == 'I')
        {
            string num = v.substr(2, v.size() - 2);
            int number = stoi(num);
            q1.push(number);
            q2.push(number);
            hash[number]++;
            qsize++;
        }
        else
        {   
            if (qsize<=0)
                continue;
            else if (v[2] == '1')
            {
                int max=q2.top();
                q2.pop();
                hash[max]--;
                qsize--;

            }
            else
            {
                int min = q1.top();
                q1.pop();
                hash[min]--;
                qsize--;
            }

        }
    }
    while (!q2.empty()&&hash[q2.top()] < 1)
    {
        
            q2.pop();
        
    }
    while (!q1.empty()&&hash[q1.top()] < 1)
    {
       
            q1.pop();
        
    }
    if (qsize >= 1)
    {
        answer.push_back(q2.top());
        answer.push_back(q1.top());
    }
    else
    {
        answer = { 0,0 };
    }

    return answer;
}

int main()
{
    vector<string> test = {"I 1","I 2","I 3","D 1","D -1","D 1","I 4"};
    for (int i : solution(test))
        cout << i << "\t";
}