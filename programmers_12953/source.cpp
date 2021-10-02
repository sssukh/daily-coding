#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    unordered_map<int, int> map;
    for (int v : arr)
    {
        unordered_map<int, int> counter;
        int tmp = v;
        int divisor = 2;
        while (divisor <= tmp)
        {
            if (tmp % divisor == 0)
            {
                counter[divisor]++;
                tmp = tmp / divisor;
            }
            else
            {
                divisor++;
            }
        }
        for (auto iter : counter)
        {
            if (map[iter.first] < iter.second)
                map[iter.first] = iter.second;

        }
    }
    for (auto iter : map)
        answer *= pow(iter.first, iter.second);
    return answer;
}