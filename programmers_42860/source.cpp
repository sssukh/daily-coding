#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int solution(string name) {
    int answer = 0;
    unordered_map<char, int> alphabet_counter_list;
    alphabet_counter_list['A'] = 0;
    alphabet_counter_list['B'] = 1;
    alphabet_counter_list['C'] = 2;
    alphabet_counter_list['D'] = 3;
    alphabet_counter_list['E'] = 4;
    alphabet_counter_list['F'] = 5;
    alphabet_counter_list['G'] = 6;
    alphabet_counter_list['H'] = 7;
    alphabet_counter_list['I'] = 8;
    alphabet_counter_list['J'] = 9;
    alphabet_counter_list['K'] = 10;
    alphabet_counter_list['L'] = 11;
    alphabet_counter_list['M'] = 12;
    alphabet_counter_list['N'] = 13;
    alphabet_counter_list['O'] = 12;
    alphabet_counter_list['P'] = 11;
    alphabet_counter_list['Q'] = 10;
    alphabet_counter_list['R'] = 9;
    alphabet_counter_list['S'] = 8;
    alphabet_counter_list['T'] = 7;
    alphabet_counter_list['U'] = 6;
    alphabet_counter_list['V'] = 5;
    alphabet_counter_list['W'] = 4;
    alphabet_counter_list['X'] = 3;
    alphabet_counter_list['Y'] = 2;
    alphabet_counter_list['Z'] = 1;
    
    vector<int> incorrect_char_list;

    for (int i=0;i<name.size();i++)
    {
        answer += alphabet_counter_list[name[i]];
        if (name[i] != 'A')
            incorrect_char_list.push_back(i);
    }

    int current_pos = 0;

    while (!incorrect_char_list.empty())
    {
        vector<int> distance_list;
        for (int idx : incorrect_char_list)
        {
            if (idx <= current_pos)
            {
                distance_list.push_back(current_pos - idx);
            }

            else if (idx > current_pos)
            {
                distance_list.push_back(min((current_pos - idx) + name.size(), idx - current_pos));
            }
        }
        int min_move = 0;
        if (distance_list[0] < distance_list.back())
        {
            answer += distance_list[0];
            current_pos = incorrect_char_list[0];
            incorrect_char_list.erase(incorrect_char_list.begin());
        }
        else
        {
            answer += distance_list.back();
            current_pos = incorrect_char_list.back();
            incorrect_char_list.pop_back();
        }

        
    }

    return answer;
    



   
    


    int idx = 0;
    int max_A_length = 0;
    int current_A_length = 0;
    int A_start_idx = 0;
    int A_finish_idx = 0;

    while (idx < name.size() || name[(idx) % name.size()]=='A')
    {
        if (name[idx%name.size()] == 'A')
        {
            current_A_length++;
        }
        else
        {
            current_A_length = 0;
        }
        if (max_A_length <= current_A_length)
        {
            max_A_length = current_A_length;
            A_finish_idx = idx;
            if (A_finish_idx >= name.size())
                A_finish_idx -= name.size();
        }
        idx++;
    }
    int add = 0;
    if (max_A_length > 0)
    {
        A_start_idx = A_finish_idx - (max_A_length-1);
        if (A_start_idx < 0)
            A_start_idx += name.size();
        if (A_start_idx < A_finish_idx)
        {
            

            add = min(A_start_idx, name.size() - A_finish_idx) - 1;
        }
        else if (A_start_idx > A_finish_idx)
        {
            add = min(name.size() - A_start_idx, A_finish_idx) + 1;
        }
    }
    cout << add <<" "<<max_A_length<< endl;


    return add<max_A_length? answer - max_A_length-1+add : answer-1;
}

int main()
{
    cout << solution("BBBBAABBB");
}