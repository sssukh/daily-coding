
#include <vector>

using namespace std;



int solution(int n) {
    int answer = 0;
    vector<int> fibonacci(n+1, 0);
    fibonacci[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1234567;
    }
    return fibonacci.back();
}

