#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) 
{
    int answer = 0;

    int idxA = 0;
    int idxB = 0;
    int size = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while (idxB < size)
    {
        if (A[idxA] < B[idxB])
        {
            ++idxA;
            ++answer;
        }
        ++idxB;
    }

    return answer;
}