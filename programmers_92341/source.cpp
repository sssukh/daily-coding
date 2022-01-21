#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    map<string, pair<int,int>> parking;    //차량번호, (현재 시간, 총 주차시간)

    for (int i = 0; i < records.size(); i++)
    {
        string tmp = records[i];
        int time = stoi(tmp.substr(0, 2)) * 60 + stoi(tmp.substr(3, 2));
        string carNumber = tmp.substr(6, 4);

        if (tmp[11] == 'I')
        {
            // map에 시간 입력
            parking[carNumber].first = time;
        }
        else
        {
            // map에 들어있는 값과 현재 time에 있는 값 빼기연산해서 시간 저장.
            // map에 들어있는 값 -1로 갱신시키기(이미 출차가 되었는지 아닌지 확인하기 위함)
            parking[carNumber].second += time - parking[carNumber].first;
            parking[carNumber].first = -1;
        }
    }

    //map를 돌면서 출차가 안되었으면 23:59로 출차시키기.
    for (auto iter : parking)
    {
        if (iter.second.first != -1)
        {
            iter.second.second += 23 * 60 + 59 - iter.second.first;
        }

        if (iter.second.second < fees[0])
            answer.push_back(fees[1]);
        else
        {
            int cal_time =iter.second.second - fees[0];
            if (cal_time % fees[2])
                cal_time = cal_time / fees[2] + 1;
            else
                cal_time = cal_time / fees[2];


            int fee = fees[1] + cal_time * fees[3];
            answer.push_back(fee);
        }

        cout << answer.back() << endl;
    }


    return answer;
}