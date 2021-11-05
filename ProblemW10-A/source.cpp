#include<vector>
#include <iostream>
#include<string>
#include <queue>

using namespace std;



int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;
			vector<int> rooms(10000, 0);
			queue<pair<int,int>> visit;
			visit.push(make_pair(A,0));
			
			while (!visit.empty())
			{
				int tmp = visit.front().first;
				int tmp_min = visit.front().second;
				visit.pop();
				if (tmp < 0 || tmp>9999)
					continue;
				if (rooms[tmp] == 0)
				{
					rooms[tmp] = tmp_min;
					if (tmp == B)
					{
						cout << tmp_min << endl;
						break;
					}
					visit.push(make_pair(tmp + 1, tmp_min + 1));
					visit.push(make_pair(tmp - 1, tmp_min + 1));
					tmp = 10000 + tmp;
					string str_tmp = to_string(tmp).substr(1, 4);
					string rev = "";
					for (int i = 3; i >= 0; i--)
						rev += str_tmp[i];
					visit.push(make_pair(stoi(rev), tmp_min + 1));
				}
			}
	}
}