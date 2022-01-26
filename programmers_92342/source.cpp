#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define infoSize 11
using namespace std;


vector<int> solution(int n, vector<int> info) 
{
    vector<int> answer = { -1 };
    int current_value = 0;
    for (int kinds_of_scores = n; kinds_of_scores >= 1; kinds_of_scores--)
    {
        vector<bool> cases(kinds_of_scores, 1);
        for (int zeros = 0; zeros <= n - kinds_of_scores; zeros++)
        {
            cases.push_back(0);
        }

        do
        {
            int current_arrows = n;
            int ryan_score = 0;
            int peach_score = 0;
            vector<int> tmp( 11,0 );
           
            for (int idx = 0; idx < infoSize; idx++)
            {
                
                if (!cases[idx] || current_arrows <= 0)
                {
                    if(info[idx])
                    peach_score += 10 - idx;
                }
                else
                {
                    if (current_arrows < info[idx] + 1)
                    {
                        tmp[idx] = current_arrows;
                        current_arrows = 0;
                        peach_score += 10 - idx;
                        
                    }
                    else
                    {
                        current_arrows -= info[idx] + 1;
                        ryan_score += 10 - idx;
                        tmp[idx] = info[idx] + 1;
                      
                    }
                }
               
            }

            if (current_arrows==0&&ryan_score - peach_score >= current_value)
            {
                if (current_value == ryan_score - peach_score)
                {
                    for (int check_idx = 10; check_idx >= 0; check_idx--)
                    {
                        if (answer[check_idx] < tmp[check_idx])
                        {
                            answer = tmp;
                            current_value = ryan_score - peach_score;
                            break;
                        }
                        else if (answer[check_idx] > tmp[check_idx])
                            break;
                    }
                }
                else
                {
                    answer = tmp;
                    current_value = ryan_score - peach_score;
                }
                /*
                cout << ryan_score - peach_score << endl;
                for (int i = 0; i < infoSize; i++)
                {
                    cout << tmp[i] << " ";
                }
                cout << endl;
                */
            }
        } while (prev_permutation(cases.begin(), cases.end()));
    }

    return answer;
}