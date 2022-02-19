#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int cover5g = 2 * w + 1;
    int prev_station = stations[0];
    int current_station;
    for (int i = 1; i < stations.size(); i++)
    {
        int distance_between_stations = stations[i] - stations[i - 1] - 2 * w - 1;
        //cout << distance_between_stations << endl;
        if (distance_between_stations > 0)
        {
            answer += distance_between_stations / cover5g;
            if (distance_between_stations % cover5g > 0)
            {
                answer++;
            }
            //cout << "answer : "<<answer << endl;
        }
    }
    int first_distance = stations.front() - 1 - w;
    //cout << "first : "<<first_distance << endl;
    if (first_distance > 0)
    {
        answer += first_distance / cover5g;
        if (first_distance % cover5g > 0)
        {
            answer++;
        }
        //cout << "answer : " << answer << endl;
    }
    int last_distance = n - stations.back() - w;
    //cout << "last : "<<last_distance << endl;
    if (last_distance > 0)
    {
        answer += last_distance / cover5g;
        if (last_distance % cover5g > 0)
        {
            answer++;
        }
        //cout << "answer : " << answer << endl;
    }

    return answer;
}