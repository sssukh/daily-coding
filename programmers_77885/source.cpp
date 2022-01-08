#include <string>
#include <vector>
#include <iostream>

using namespace std;

int checkbits(long long added_input)
{
    cout << added_input;
    int count = 0;
    while (added_input > 0)
    {
        if (added_input % 2)
            count++;
        added_input /= 2;
    }
    cout << " " << count << endl;
    return count;
}

long long func(long long input)
{
    long long adder = 1;
    while (true)
    {
        if (checkbits((input + adder)^input) <= 2)
            return input + adder;
        adder = adder<<1;
        cout << adder << endl;
    }
}


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        answer.push_back(func(numbers[i]));
    }

    return answer;
}

int main()
{
     solution({ 3,7 });
}