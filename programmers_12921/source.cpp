#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int p = 2;
    vector<bool> numbers;
    for (int i = 0; i <= n; i++)
    {
        numbers.push_back(true);
    }
    numbers[0] = false; numbers[1] = false;
    while (p * p < n)
    {
        for (int i = p*2; i <= n; i+=p)
        {   
            numbers[i] = false;
        }



        p++;
    }
    for (bool v : numbers)
    {
        if (v == true)
            answer++;
    }

    return answer;
}