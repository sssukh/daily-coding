#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;


//gems를 순회하면서 unordered_map에 gem의 index를 추가한다. 
vector<int> solution(vector<string> gems) {
    vector<int> answer{ 2,0 };
    deque<int> gems_position;
    unordered_map<string, int> gems_type;
    int gems_type_cnt = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        gems_type[gems[i]]++;
        gems_position.push_back(i);
        if (gems_type_cnt != gems_type.size())
        {
            gems_type_cnt++;
            answer[0] = gems_position.front() + 1;
            answer[1] = gems_position.back() + 1;
        }
        else
        {
            while (gems_position.size()>1&&gems_type[gems[gems_position.front()]]>1)
            {
                gems_type[gems[gems_position.front()]]--;
                gems_position.pop_front();
            }
            if (answer[1] - answer[0] > gems_position.back() - gems_position.front())
            {
                answer[0] = gems_position.front() + 1;
                answer[1] = gems_position.back() + 1;
            }
        }
    }


    return answer;
}