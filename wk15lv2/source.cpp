#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<char> V;
vector<bool> VC;
vector<int> primes;

void DFS(int, int, int, string);
void IsPrime();

int solution(string numbers) {
    int answer = 0;

 
    for (int i = 0; i < numbers.size(); i++)
    {
        VC.push_back(false);
    }

    for (int i = 1; i <= numbers.size(); i++)
    {
        DFS(0, i, numbers.size(), numbers);
    }
    answer = primes.size();
    return answer;
}

void DFS(int Cnt,int Get,int size,string numbers)
{
    if (Cnt == Get)
    {
        //cout << "Get : " << Get << endl;
        IsPrime();
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (VC[i] == true) continue;
        VC[i] = true;
        V.push_back(numbers[i]);
        DFS(Cnt + 1, Get, size, numbers);
        V.pop_back();
        VC[i] = false;
    }
}

void IsPrime()
{   
    /*
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i];
    }
    cout << endl;
    */


    string tmp = "";
    for (int i = 0; i < V.size(); i++)
    {
        tmp += V[i];
    }
    int chk = stoi(tmp);

    if (chk == 0||chk==1)
        return ;

    for (int i = 2; i * i <= chk; i++)
    {
        if (chk % i == 0)
        {
            return ;
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] == chk)
        {
            return;
        }

    }
    primes.push_back(chk);
}



int main()
{
    cout << solution("011");
    
    return 0;
}