#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), cmp);
    
    for (int i = citations[0]; i > 0; i--)
    {
        int cnt = 0;//h 번 이상 인용된 논문 편 수
        for (int j = 0; j < citations.size(); j++)
        {
            if (i <= citations[j])
            {
                cnt++;
            }
            else 
                break;
            if (cnt >= i)
                return cnt; 
        } 
    }

    return answer;
}

int main()
{
    vector<int> test = { 2,1,2,1,2,1,1,1};
    cout << solution(test) << endl;
}