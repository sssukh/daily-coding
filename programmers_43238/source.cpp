#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    int counterSize = times.size();
    sort(times.begin(), times.end());


    long long left=1;
    long long right=times.back()*(long long)n;
    while (right>left)
    {   
        long long cnt = 0;
        answer = (right + left) /2;
        for (int i = 0; i < counterSize; i++)
        {
            cnt += answer / times[i];
        }
        if (cnt >=(long long) n)
        {
            right = answer;
        }
        else
        {
            left = answer + 1;
        }
        cout << right << " " << answer << " " << left << " " << cnt << endl;
    }

    return answer=left;

}

int main()
{
    cout<<solution(3, { 1,1,1 });

}