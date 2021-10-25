#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    string head_a="";
    string head_b="";
    int aSize = a.size();
    int bSize = b.size();
    int aDigitBegin;
    int bDigitBegin;
    for (int i = 0; i < aSize; i++)
    {
        if (isdigit(a[i]))
        {
            aDigitBegin = i;
            break;
        }
        head_a += tolower(a[i]);
    }
    for (int i = 0; i < bSize; i++)
    {
        if (isdigit(b[i]))
        {
            bDigitBegin = i;
            break;
        }
        head_b += tolower(b[i]);
    }
    
    if (head_a == head_b)
    {
        string aNum = "";
        string bNum = "";
        for (int i = aDigitBegin; i < aSize; i++)
        {
            if (!isdigit(a[i]))
                break;
            aNum += a[i];
        }
        for (int i = bDigitBegin; i < bSize; i++)
        {
            if (!isdigit(b[i]))
                break;
            bNum += b[i];
        }
        return stoi(aNum) < stoi(bNum);
    }
    return head_a < head_b;
}

vector<string> solution(vector<string> files) {//atoi, isdigit
    vector<string> answer;
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}