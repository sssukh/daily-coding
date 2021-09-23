#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 1;
    sort(people.begin(), people.end(),cmp);
    int current_limit = limit;
    for(int i=0;i<people.size();i++)
    {
        if (current_limit > people[i])
        {
            current_limit -= people[i];
        }
        else if (current_limit == people[i])
        {
            current_limit = limit;
            answer++;
        }
        else {
            int light = people.back();
            if (current_limit - light > 0)
            {
                current_limit -= light;
                people.pop_back();
            }
            else if (current_limit - light == 0)
            {
                answer++;
                current_limit = limit;
                people.pop_back();
            }
            else
            {
                answer++;
                current_limit = limit;
            }
            i--;
        } 
    }
    return current_limit==limit? answer-1:answer;
}