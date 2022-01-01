#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}


int solution(int n, vector<int> money) {
    int answer = 0;

    sort(money.begin(), money.end(), cmp);
    vector<int> cases(n + 1, 0);
    cases[0] = 1;
    for (int j=0;j<money.size();j++)
    {
        for (int i=0;i<=n;i++)
        {
            if (i - money[j] >= 0)
                cases[i] += cases[i - money[j]];
        }
    }

    return cases[n];
}