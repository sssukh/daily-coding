#include <string>
#include <vector>
#include <iostream>

using namespace std;


long long factorial(int n)
{
    long long tmp = 1;
    for (int i = 2; i <= n; ++i)
    {
        tmp *= i;
    }
    return tmp;
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;
    vector<int> nums;
    for (int i = 1; i <= n; ++i)
    {
        nums.push_back(i);
    }
    long long counting = 1;
    int current_answer_idx = 0;
    while (!nums.empty())
    {
        int current_nums_idx = 0;
        long long add = factorial(n - current_answer_idx - 1);
        cout << add << endl;
        while (counting + add <= k)
        {
            counting += add;
            ++current_nums_idx;
            //cout << "count : " << counting << " idx : " << current_nums_idx << endl;
        }
        answer.push_back(nums[current_nums_idx]);
        nums.erase(nums.begin() + current_nums_idx);
        current_answer_idx++;
    }
    
    

    return answer;
}

int main()
{
    unsigned long long test = -1;
    long long test2 = 1;
    test2 = test2 << 63;
    test2 -= 1;
    cout << test << endl;
    cout << test2 << endl;
    cout << factorial(19) << endl;
    solution(20, 2394985098);
}