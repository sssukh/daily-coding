#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int rows = relation.size();
    int cols = relation[0].size();
    vector<int> keys;
    for (int i = 1; i <= cols; i++)
    {
        vector<int> picks(cols - i, 0);
        for (int j = 0; j < i; j++ )
            picks.push_back(1);
        do
        {
            int tmp = 0;
            bool check = false;
            for (int col = 0; col < cols; col++)
            {
                tmp += picks[col] << col;
            }
            for (int key : keys)
            {
                int result = key & tmp;
                if (result ==key)
                {
                    check = true;
                    break;
                }
            }
            if (check) continue;
            bool is_key = true;
            unordered_map<string, int> db;
            for (int row = 0; row < rows; row++)
            {
                string tmp = "";
                for (int col = 0; col < cols; col++)
                {
                    if (picks[col] == 1)            //고른 col들의 조합 만들기
                    {
                        tmp += relation[row][col];
                    }
                }
                if (++db[tmp] > 1)                  //중복값 있으면
                {
                    is_key = false;
                    break;
                }
            }
            if (is_key)
            {
                int bits = 0;
                for (int col = 0; col < cols; col++)
                {
                    bits += picks[col] << col;
                }
                keys.push_back(bits);
            }

        } while (next_permutation(picks.begin(), picks.end()));
    }
   
    return keys.size();
}


int main()
{
    vector<vector<string>> test = { {"a","1","aaa","c","ng"},
{"a","1","bbb","e","g"},
{"c","1","aaa","d","ng"},
{"d","2","bbb","d","ng"} };

    cout<<solution(test);
}