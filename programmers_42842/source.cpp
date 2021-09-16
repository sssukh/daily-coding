#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
 
    int total = brown + yellow;
    for (int i = 1; i * i <= yellow; i++)
    {
        int other;
        if (yellow % i == 0)
        {
            other = yellow / i;
        }
        if ((i + 2) * (other + 2) == total)
        {
            if (i > other)
            {
                return { i + 2,other + 2 };
            }
            else
            {
                return { other + 2,i + 2 };
            }
        }
    }
}