#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DFS(int start, vector<vector<bool>>& tree,int n,vector<int>& visit,int& answer)
{
    visit[start] = 1;
    cout << start << endl;
    for (int i = 1; i <= n; i++)
    {
        if (tree[start][i]>0&&visit[i]==0)
        {
            cout << "visit   " << i << endl;
            visit[start]+= DFS(i, tree, n, visit,answer);
            cout << "go up" << endl;
        }
    }
    if (answer > abs(n - 2 * visit[start]))
        answer = abs(n - 2 * visit[start]);
    return visit[start];
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    vector<vector<bool>> tree(n+1,vector<bool>(n+1,0));
    vector<int> visit(n+1, 0);
    for (int i = 0; i < n-1; i++)
    {
        int tmp1 = wires[i][0];
        int tmp2 = wires[i][1];
        tree[tmp1][tmp2] = 1;
        tree[tmp2][tmp1] = 1;
    }
   
    DFS(1, tree, n, visit, answer);

    for (int i = 1; i <= n; i++)
        cout << visit[i]<<" ";

    return answer;
}


int main()
{
    vector<vector<int>> test = { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
    cout<<solution(9,test);
}