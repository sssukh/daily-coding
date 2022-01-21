#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    map<string, pair<int,int>> parking;    //������ȣ, (���� �ð�, �� �����ð�)

    for (int i = 0; i < records.size(); i++)
    {
        string tmp = records[i];
        int time = stoi(tmp.substr(0, 2)) * 60 + stoi(tmp.substr(3, 2));
        string carNumber = tmp.substr(6, 4);

        if (tmp[11] == 'I')
        {
            // map�� �ð� �Է�
            parking[carNumber].first = time;
        }
        else
        {
            // map�� ����ִ� ���� ���� time�� �ִ� �� ���⿬���ؼ� �ð� ����.
            // map�� ����ִ� �� -1�� ���Ž�Ű��(�̹� ������ �Ǿ����� �ƴ��� Ȯ���ϱ� ����)
            parking[carNumber].second += time - parking[carNumber].first;
            parking[carNumber].first = -1;
        }
    }

    //map�� ���鼭 ������ �ȵǾ����� 23:59�� ������Ű��.
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