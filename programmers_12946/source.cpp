#include <string>
#include <vector>
#include <iostream>

using namespace std;

void move(int start, int end, int theother, int qty,vector<vector<int>>& answer)
{
    if(qty>1)
        move(start, theother, end, qty-1,answer);

    answer.push_back({ start,end });
    cout << start << " " << end << endl;

    if (qty > 1)
        move(theother, end, start, qty - 1, answer);

}

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;
    

    move(1, 3, 2, n, answer);


    return answer;
}