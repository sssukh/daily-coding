#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b)
    {
        answer++;
        if (a % 2)
            a = (a + 1) / 2;
        else
            a /= 2;
        if (b % 2)
            b = (b + 1) / 2;
        else
            b /= 2;
        if (a < 1) a = 1;
        if (b < 1) b = 1;
    }

    return answer;
}

