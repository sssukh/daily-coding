#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define INF 1e8

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[2] > b[2];
    }
};

vector<int> dijk(vector<vector<int>>& map, int start, int end)
{
    vector<int> result(map.size(), 0);
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;  //시작하는 노드, 도착하는 노드, 택시비
    int current_node = start;
    int cnt = 0;
    while (current_node!=end&&cnt<map.size()-1)
    {
        //cout << "current node : "<<current_node << endl;
        /*
        for (int i : result)
            cout << i << " ";
        cout << endl;
        */
        for (int i = 1; i < map.size(); i++)
        {
            if (i == start)
                continue;
            if (map[current_node][i]&&result[i]==0)
            {
                q.push({ current_node,i, map[current_node][i] + result[current_node] });
            }
        }
       
        while (!q.empty()&&result[q.top()[1]])
            q.pop();
        if (q.empty())
            break;
        result[q.top()[1]] = q.top()[2];
        current_node = q.top()[1];
        cnt++;
        q.pop();
    }
    return result;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<int>> map(n + 1, vector<int>(n + 1,0));
    for (int i = 0; i < fares.size(); i++)
    {
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int i = 1; i < map.size(); i++)
    {
        for (int j = 1; j < map.size(); j++)
        {
            if (i!=j&&map[i][j] == 0)
            {
                map[i][j] = INF;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
    for (int i = 1; i < map.size(); i++)
    {
        answer = min(answer, map[s][i] + map[i][a] + map[i][b]);
    }
    /*
    vector<int> from_start;
    from_start = dijk(map, s,n + 1);
    
    for (int i : from_start)
        cout << i << " ";
    cout << endl;
    
    for (int i = 1; i <= n; i++)
    {
        if (i == s )
            continue;
        vector<int> tmp = dijk(map, i, n + 1);
        if (from_start[i])
        {
            if (answer == 0)
                answer = from_start[i] + tmp[a] + tmp[b];
            else
                answer = min(answer, from_start[i] + tmp[a] + tmp[b]);
            //cout << "answer : " << answer << " i : " << i << endl;
        }
    }

    answer = min(answer, from_start[a] + from_start[b]);
    */
    
    return answer;
}

int main()
{
    vector<vector<int>> test1 = { {4,1,10},{3,5,24},{5,6,2},{3,1,41},{5,1,24},{4,6,50},{2,4,66},{2,3,22},{1,6,25} };
    vector<vector<int>> test2 = { {5,7,9},{4,6,4},{3,6,1},{3,2,3},{2,1,6} };
    vector < vector<int>> test3 = { {2,6,6},{6,3,7},{4,6,7},{6,5,11},{2,5,12},{5,3,20},{2,4,8},{4,3,9} };
    cout<<solution(7, 3, 4, 1, test2);
}