#include <string>
#include <vector>


using namespace std;



vector<int> solution(int n, int s) {
    vector<int> answer;

    int tmp = s / n;
    if (tmp == 0)
        return { -1 };
    for (int i = 0; i < n; i++)
    {
        answer.push_back(tmp);
    }
    int remainder = s % n;
    for (int i = 0; i < remainder; i++)
    {
        answer[n - 1 - i]++;
    }

    return answer;
}