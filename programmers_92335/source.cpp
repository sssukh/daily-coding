#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    string num = "";
    multiset<int> numbers_for_prime;
    string tmp = "";
    
    while (n > 0)
    {
        num+=to_string(n % k);
        n /= k;
    }

    

    int numSize = num.size();
    for (int idx = numSize-1; idx >= 0 ; idx--)
    {
        if (num[idx] != '0')
        {
            tmp += num[idx];
        }
        else
        {
            if (tmp != "")
                numbers_for_prime.insert(stoi(tmp));
            tmp = "";
        }
    }
    if (tmp != "")
        numbers_for_prime.insert(stoi(tmp));

   
    for (auto iter = numbers_for_prime.begin(); iter != numbers_for_prime.end(); iter++)
    {
        int check;
        int root = sqrt(*iter);
        cout << *iter << " " << root << endl;
        for (check = 2; check <= root; check++)
        {
            if ((*iter % check)==0)
                break;
        }
        if (check == root + 1)
            ++answer;
    }


    /*
    int max = *numbers_for_prime.crbegin();
    
    vector<bool> isnotPrime( max + 1 , 0);
    isnotPrime[0] = isnotPrime[1] = 1;
    for (int number = 2; number < isnotPrime.size(); number++)
    {
        if (!isnotPrime[number])
        {
            for (int checking = number * 2; checking < isnotPrime.size(); checking += number)
            {
                //cout << checking << endl;
                isnotPrime[checking] = true;
            }
        }
    }

    for (auto iter = numbers_for_prime.begin(); iter != numbers_for_prime.end(); iter++)
    {
        //cout << *iter << endl;
        if (!isnotPrime[*iter])
            ++answer;
    }
    */

    return answer;
}

int main()
{
    cout << solution(437674, 3) << endl;
}