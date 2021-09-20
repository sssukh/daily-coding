#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    if (N == number)
        return 1;
    int answer = -1;
    unordered_set<int> S[8];
    int base = 0;
    for (int i = 0; i < 8; i++)
    {
        base = 10 * base + 1;
        S[i].insert(base * N);
    }

    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (auto& op1 : S[j])
            {
                for (auto& op2 : S[i - j - 1])
                {
                    S[i].insert(op1 + op2);
                    S[i].insert(op1 - op2);
                    S[i].insert(op1 * op2);
                    if(op2 !=0)
                        S[i].insert(op1 / op2);
                }
            }
            
        }
        if (S[i].count(number) > 0)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}