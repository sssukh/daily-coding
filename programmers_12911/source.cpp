#include <string>
#include <vector>

using namespace std;

int binary(int );

int solution(int n) {
    int answer = 0;

    int needs = binary(n);

    int tmp = -1;
    int adds = 0;
    while (tmp != needs)
    {
        adds++;
        tmp = binary(n + adds);
        
    }

    return n+adds;
}

int binary(int n)
{
    vector<bool> n_to_binary;
    while (n > 0)
    {

        n_to_binary.push_back(n % 2);
        n -= n % 2;
        n = n / 2;
    }
    int count = 0;
    for (int i :n_to_binary)
    {
        if (i == 1)
            count++;
    }
    return count;
}