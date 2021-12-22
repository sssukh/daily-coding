#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
    {
        if (a[1] == b[1])
        {
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int solution(vector<string> lines) {
    int answer = 0;

    int size = lines.size();
    vector<vector<int>> request; // 0 : start_hour, 1 : start_min, 2 : start_sec, 3 : end_hour, 4 : end_min, 5 : end_sec
    for (int i = 0; i < size; i++)
    {
        string tmp = lines[i].substr(11, 12);
        string times = lines[i].substr(23);
        times.pop_back();
        int hour = stoi(tmp.substr(0, 2));
        int minute = stoi(tmp.substr(3, 2));
        int second = (stod(tmp.substr(6))*1000);
        int last = (stod(times)*1000);
       
        int start_second = second - last + 1;
        int start_min = minute;
        int start_hour = hour;
        if (start_second < 0)
        {
            start_second += 60000;
            start_min--;
        }
        if (start_min < 0)
        {
            start_min += 60;
            start_hour--;
        }
       
        vector<int> starting_signals = { start_hour,start_min,start_second,1,i };
        vector<int> ending_signals = { hour, minute, second,-1,i };
        request.push_back(starting_signals);
        request.push_back(ending_signals);
        
        //vector<float> lasting_signals = { (float)hour,(float)minute,second,last };
        //request.push_back(lasting_signals);
    }
    sort(request.begin(), request.end(), cmp);
    vector<bool> check_list(size, 0);
    for (int i = 0; i < request.size(); i++)
    {
        int start_hour = request[i][0];
        int start_min = request[i][1];
        int start_sec = request[i][2];
        
        int last_cnt = 0;
        static int count = 0;
        if (request[i][3] == 1 && !check_list[request[i][4]])
        {
            count++;
            check_list[request[i][4]] = 1;
        }
        //cout << "count : " << count << endl;
        //cout << "start : " << start_hour << " " << start_min << " " << start_sec << " "<<request[i][3]<<endl;
        for (int j = i + 1; j < request.size(); j++)
        {
            if (start_hour == request[j][0])
            {
                if (start_min == request[j][1])
                {
                    if (start_sec + 1000 - 1 < request[j][2])
                    {
                        break;
                    }
                    else if (!check_list[request[j][4]])
                    {
                        count++;
                        check_list[request[j][4]] = 1;
                        //cout << request[j][0] << " " << request[j][1] << " " << request[j][2] << endl;
                    }
                }
                else
                {
                    if (start_min == request[j][1] - 1)
                    {
                        if (start_sec + 1000 - 1 < request[j][2] + 60000)
                        {
                            break;
                        }
                        else if (!check_list[request[j][4]])
                        {
                            count++;
                            check_list[request[j][4]] = 1;
                            //cout << request[j][0] << " " << request[j][1] << " " << request[j][2] << endl;
                        }
                    }
                    else
                        break;
                }
            }
            else if (start_hour == request[j][0] - 1)
            {
                if (start_min == request[j][1])
                {
                    if (start_sec + 1000 - 1 < request[j][2])
                    {
                        break;
                    }
                    else if (!check_list[request[j][4]])
                    {
                        count++;
                        check_list[request[j][4]] = 1;
                        //cout << request[j][0] << " " << request[j][1] << " " << request[j][2] << endl;
                    }
                }
                else
                {
                    if (start_min == request[j][1] - 1)
                    {
                        if (start_sec + 1000 - 1 < request[j][2] + 60000 )
                        {
                            break;
                        }
                        else if (!check_list[request[j][4]])
                        {
                            count++;
                            check_list[request[j][4]] = 1;
                            //cout << request[j][0] << " " << request[j][1] << " " << request[j][2] << endl;
                        }
                    }
                    else
                        break;
                }
            }
            else
                break;
           
        }
        answer = max(answer, count);

        if (request[i][3] == -1)
        {
            count--;
            //check_list[request[i][4]] = 0;
        }
    }

    return answer;
}