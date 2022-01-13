#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool check(vector<string>& data, vector<int>& cases,unordered_map<char,int>& friends_idx)
{
   
    for (int i = 0; i < data.size(); i++)
    {
        int first = friends_idx[data[i][0]];
        int second = friends_idx[data[i][2]];
        
        int first_idx, second_idx;
        for (int j = 0; j < cases.size(); j++)
        {
            if (first == cases[j])
                first_idx = j;
            else if (second == cases[j])
                second_idx = j;
        }
        int tmp = abs(first_idx - second_idx)-1;
        //cout <<first_idx<<" "<<second_idx<<" "<< tmp << endl;
        int value = data[i][4] - '0';
        if (data[i][3] == '=')
        {
            if (tmp != value)
                return false;
        }
        else if (data[i][3] == '<')
        {
            if (tmp >= value)
                return false;
        }
        else
        {
            if (tmp <= value)
                return false;
        }
    }
    return true;
}

int solution(int n, vector<string> data) {
    int answer = 0;

    vector<int> cases = { 0,1,2,3,4,5,6,7 };
    vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    unordered_map<char, int> friends_idx;
    for (int i = 0; i < friends.size(); i++)
    {
        friends_idx[friends[i]] = cases[i];
    }


    do
    {
        if (check(data, cases, friends_idx))
            answer++;
        /*
        for (int i : cases)
            cout << i << " ";
        cout << endl;
        */
    } while (next_permutation(cases.begin(),cases.end()));

    return answer;
}

int main()
{
    vector<string> test = { "N~F=0", "R~T>2" };
    cout << solution(2,test) << endl;
}