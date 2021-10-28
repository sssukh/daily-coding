#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b)
{
    return a < b;
}

bool musicCmp(string m, string music, int time)
{
    int mSize = m.size();
    int musicSize = music.size();
    for (int i = 0; i < time; i++)
    {
        if (m[0] == music[i % musicSize] && time - i >= mSize)
        {
            int start = i % musicSize;
            int idx = 0;
            bool is_equal = true;
            //cout << start << endl;
            while (idx < mSize)
            {
                if (m[idx] != music[start%musicSize])
                {
                    is_equal = false;
                    break;
                }
                idx++;
                start++;
            }
            
            if (is_equal)
                return true;
        }
        else if (time - i < mSize)
            break;
    }
    return false;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int answer_time = 0;

    int musicinfosSize = musicinfos.size();

    for (int i = 0; i < musicinfosSize; i++)
    {
        int musicSize = musicinfos[i].size();
        vector<string> infos(6, "");
        int info_idx = 0;
        for (int j = 0; j < musicSize; j++)
        {
            if (musicinfos[i][j] == ':' || musicinfos[i][j] == ',')
            {
                info_idx++;
            }
            else if (info_idx==5&&musicinfos[i][j] == '#')
            {
                infos[info_idx].back() = tolower(infos[info_idx].back());
            }
            else
            {
                infos[info_idx] += musicinfos[i][j];
            }
        }
        
        int hour = stoi(infos[2])-stoi(infos[0]);
        int min = stoi(infos[3])-stoi(infos[1]);
        if (hour < 0)
            hour = 24 - stoi(infos[0]);
        string musicName = infos[4];
        string music = infos[5];
        string neo = "";
        for (int a = 0; a < m.size(); a++)
        {
            if (m[a] == '#')
            {
                neo.back() = tolower(neo.back());
            }
            else
                neo += m[a];
        }
        
       
        int time = 60 * hour + min;
        //cout << hour << " " << min << " " <<time<<" " << musicName << " " << music << endl;
        if (musicCmp(neo, music, time))
        {
           
            if (time > answer_time)
            {
                answer = musicName;
                answer_time = time;
            }

        }

    }

    return answer==""?"(None)":answer;
}

int main()
{
    vector<string> test = { "13:55,14:00,TEST1,ABCDEF","14:55,15:05,TEST2,ABCDEF","15:55,16:00,TEST3,ABCDEF" };
    cout<<solution("ABC", test)<<endl;
}