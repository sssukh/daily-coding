#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> list;
    
    for (int v : nums)
    {
        if (list[v] != 0)
        {
            continue;
        }
        else
        {
            list[v]++;
            answer++;
    
        }
        if (answer >= nums.size()/2)
            return nums.size()/2;
    }
    
    return answer;
}