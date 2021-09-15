#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i : scoville) q.push(i);
    while (true)
    {
        int min1 = q.top();
        q.pop();
        if (min1 > K)break;
        else if (q.empty())
        {
            return -1;
        }
        int min2 = q.top();
        q.pop();
        q.push(min1 + 2 * min2);
        answer++;
    }
    return answer;
}