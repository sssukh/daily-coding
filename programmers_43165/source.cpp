#include<math.h>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> numbers_map(2,0);
    int cur_idx = 2;
    for (int i = 0; i < numbers.size(); i++)
    {
        int num = pow(2, i+1);
        for (int j = 0; j < num; j++)
        {
            if (j % 2 == 0) 
            {
                numbers_map.push_back(numbers_map[(int)(cur_idx / 2)]+numbers[i]);
              
            }
            else
            {
                numbers_map.push_back(numbers_map[(int)(cur_idx / 2)]-numbers[i]);
               
            }
            cur_idx++;
           
        }
      
    }
    for (int i = pow(2, numbers.size()); i < numbers_map.size(); i++)
    {
        if (numbers_map[i] == target)
            answer++;
    }

    return answer;
}


