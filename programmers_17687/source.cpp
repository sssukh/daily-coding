#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string num = "0123456789ABCDEF";
    string game = "";
    int number = 0;
    int count = 0;
    while (count < t)
    {
        int tmp = number;
        string current = "";
        do
        {
            current += num[tmp % n];
            //tmp -= tmp % n;
            tmp /= n;
            cout << current << endl;
        } while (tmp != 0);
        for (int i = current.size()-1; i >=0; i--)
        {
            game += current[i];
        }


        while (game.size()>(count*m+p)&&count<t)
        {
            answer += game[count * m + p - 1];
            count++;
        }
        number++;
    }
    return answer;
}

int main()
{
    cout << solution(16, 16, 2, 1) << endl;
}