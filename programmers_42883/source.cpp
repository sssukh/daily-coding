#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = 0; i < number.size(); i++)
    {
        while (!answer.empty() && answer.back() < number[i]
            && k > 0)
        {
            answer.pop_back();
            k--;
        }
        if (k == 0)
        {
            answer += number.substr(i, number.size() - 1);
            break;
        }

        answer += number[i];
    }


    return answer.substr(0, answer.size() - k);
}