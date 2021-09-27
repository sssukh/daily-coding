
#include<vector>
#include<algorithm>
using namespace std;


int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end(),greater<int>());
    sort(B.begin(), B.end(),less<int>());
    while (!A.empty())
    {
        answer += A.back() * B.back();
        A.pop_back();
        B.pop_back();
    }
   

    return answer;
}