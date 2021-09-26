#include <string>
#include <vector>
#include <algorithm>

using namespace std;



string solution(string s) {
    string answer = "";
    vector<int> numbers;
    string tmp = "";
    for (char cur : s)
    {
        if (cur == ' ') 
        {
            numbers.push_back(stoi(tmp));
            tmp = "";
        }
        else
            tmp += cur;
    }
    numbers.push_back(stoi(tmp));
    sort(numbers.begin(), numbers.end());
    answer = to_string(numbers.front()) + " " + to_string(numbers.back());
    return answer;
}