#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

// DFS(bool isClockwise, int start, int idx, int size, vector<int>& weak, vector<int> dist) 

int solution(int n, vector<int> weak, vector<int> dist) //현재 풀이는 weak point들의 범위로 조사하는데 범위아닌 point를 
{                                                       //커버하는 방향으로 풀어보자
    int answer = -1;
    int weakSize=weak.size();
    int distSize = dist.size();
    //sort(dist.begin(), dist.end(),cmp);
    vector<int> cases;
    for (int i = 0; i < distSize; i++)
    {
        cases.push_back(i);
    }

    do
    {
        vector<int> tmp_dist;
        for (int i = 0; i < distSize; i++)
        {
            tmp_dist.push_back(dist[cases[i]]);
        }
        for (int start_adder = 0; start_adder < weakSize; start_adder++)
        {
            int dist_idx = 0;
            int clockwise_start = weak[start_adder];
            int counterclockwise_start = weak[start_adder];
            bool hasJumped = false;
            int weak_idx;

            //cout << "start : " << clockwise_start << endl;

            // clockwise
            for (weak_idx = 1; weak_idx < weakSize; weak_idx++)
            {
                int clockwise_tmp = (-clockwise_start + weak[(weak_idx + start_adder) % weakSize] + n) % n;

                cout << "start : " << clockwise_start <<" tmp : "<<clockwise_tmp<< endl;

                if (clockwise_tmp > tmp_dist[dist_idx])
                {

                    //cout << "next dist" << endl;

                    ++dist_idx;
                    clockwise_start = weak[(weak_idx + start_adder) % weakSize];
                }
            }

            if (weak_idx == weakSize)
            {
                if (answer == -1 || answer > dist_idx)
                {
                    answer = dist_idx + 1;
                    for (int i = 0; i <= dist_idx; i++)
                    {
                        cout << tmp_dist[i] << " ";
                    }
                    cout << "dist_idx : "<< dist_idx<<endl;
                }
            }


            dist_idx = 0;

            // counterclockwise
            for (weak_idx = 1; weak_idx < weakSize; weak_idx++)
            {
                int counterclockwise_tmp = (counterclockwise_start - weak[(weakSize - weak_idx + start_adder) % weakSize] + n) % n;
                
                cout << "start : " << counterclockwise_start << " tmp: "<<counterclockwise_tmp<<endl;

                if (counterclockwise_tmp > tmp_dist[dist_idx])
                {

                    //cout << "next dist" << endl;

                    ++dist_idx;
                    counterclockwise_start = weak[(weakSize - weak_idx + start_adder) % weakSize];
                }
            }

            if (weak_idx == -1)
            {
                if (answer == -1 || answer > dist_idx)
                {
                    answer = dist_idx + 1;
                    for (int i = 0; i <= dist_idx; i++)
                    {
                        cout << tmp_dist[i] << " ";
                    }
                    cout <<"dist_idx : "<<dist_idx<< endl;
                }
            }
        }
    } while (next_permutation(cases.begin(), cases.end()));
    if (answer > dist.size())
        answer = -1;

    return answer;
}

