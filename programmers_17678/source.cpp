#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int getCrewtime(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

bool cmp(string a, string b)
{
    return a < b;
}

string timetostring(int time)
{
    int hour = 100 + time / 60;
    int min = 100 + time % 60;
    return to_string(hour).substr(1, 2) + ":" + to_string(min).substr(1,2);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    queue<int> crews;
    vector<int> last_bus;
    int answer_int;
    sort(timetable.begin(), timetable.end(), cmp);
    for (int i = 0; i < timetable.size(); i++)
    {
        crews.push(getCrewtime(timetable[i]));
    }


    for (int i = 0; i < n; i++)
    {
        int current_time = 60 * 9 + i * t;
        cout << "current time : "<<current_time << endl;
        int cnt = 0;
        while (!crews.empty()&&cnt < m && current_time >= crews.front())
        {
            cout << "crew : "<<crews.front() << endl;
            cnt++;
            if (i == n - 1)
            {
                last_bus.push_back(crews.front());
            }
            crews.pop();
        }
        if (i == n - 1 && (cnt < m || last_bus.empty()))
        {
           
            return timetostring(current_time);
        }
    }
    answer = timetostring(last_bus.back() - 1);

    return answer;
}