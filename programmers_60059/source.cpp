#include <string>
#include <vector>
#include <iostream>

using namespace std;

void clockwise(vector<vector<int>>& key)
{
    vector<vector<int>> tmp(key.size(), vector<int>(key.size(), 0));
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            tmp[j][key.size() - 1 - i] = key[i][j];
        }
    }
    key = tmp;
}

bool check(vector<vector<int>>& new_board, vector<vector<int>>& key, int start_x, int start_y, int count)
{
    //cout << start_x << " " << start_y << endl;
    int cnt = 0;
    for (int i = 0; i <key.size(); i++)
    {
        for (int j = 0; j<key.size(); j++)
        {
            if (key[i][j] & new_board[i + start_x][j + start_y])
                return false;
            if (key[i][j]&&i + start_x>=key.size()-1&&i + start_x <=new_board.size()-key.size()
                &&j + start_y>=key.size()-1&&j + start_y<=new_board.size()-key.size())
                cnt++;
        }
    }
    //cout << "cnt : " << cnt << endl;
    return count==cnt?true:false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int key_size = key.size();
    int lock_size = lock.size();
    vector<vector<int>> new_lock(2 * key_size + lock_size - 2, vector<int>(2 * key_size + lock_size - 2, 0));
    int count = 0;
    for (int i = 0; i < lock_size; i++)
    {
        for (int j = 0; j < lock_size; j++)
        {
            new_lock[i+key_size-1][j+key_size-1] = lock[i][j];
            if (lock[i][j]==0)
                count++;
        }
    }
    //cout << count << endl;
    /*
    for (int i = 0; i < new_lock.size(); i++)
    {
        for (int j = 0; j < new_lock.size(); j++)
        {
            cout << new_lock[i][j] << " ";
        }
        cout << endl;
    }
    */
    int cnt = 0;
    while (cnt<4)
    {
        for (int i = 0; i < key_size + lock_size-1; i++)
        {
            for (int j = 0; j < key_size + lock_size-1; j++)
            {
                //cout << 1 << endl;
                if (check(new_lock, key, i, j,count))
                    return true;
            }
        }
        clockwise(key);
        cnt++;
    }
    return answer;
}

int main()
{
    vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
    vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };
    cout << solution(key,lock) << endl;
}