

#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int min = 1;
    for (int i = 1; i <= n; i++)
    {
        if (sum == n)
            answer++;
        sum += i;
        while (sum > n)
        {
            sum -= min;
            min++;
        }
       
    }
    return answer+1;
}




