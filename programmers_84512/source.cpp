#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a < b;
}

int solution(string word) {
    int answer = 0;
    vector<string> basic = { "A","E","I","O","U" };
    vector<string> test = basic;
    int presize = 0;
    while (test.back().size()<5)
    {
        int size = test.size();
        for (int i = 0; i < 5; i++)
        {
            for (int j = presize; j < size; j++)
            {
                test.push_back(test[j] + basic[i]);
            }
        }
        presize = size;
    }
    sort(test.begin(), test.end(), cmp);
    for (int i = 0; i < test.size(); i++)
    {
        if (test[i] == word)
            return i + 1;
    }

    
}