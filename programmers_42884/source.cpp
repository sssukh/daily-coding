#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    int minA = min(a[0], a[1]);
    int minB = min(b[0], b[1]);
    return minA < minB;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end());

    for (int i = 0; i < routes.size(); i++)
    {
        
        int standard = max(routes[i][0], routes[i][1]);
        

        int count = 1;
        while (i + count < routes.size()&&min(routes[i + count][0], routes[i + count][1])<=standard)
        {
            standard = min(standard, max(routes[i + count][0], routes[i + count][1]));
            count++;
        }
        answer++;
        i += count - 1;
        cout << i << endl;
    }

    return answer;
}