#include <iostream>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		bool answer = true;
		string pattern;
		cin >> pattern;
		if (pattern.back() == '0')
		{
			cout << "NO" << endl;
			continue;
		}

		int idx = 0;
		bool prev_num_is_one = false;
		int one_count = 0;
		while (idx < pattern.size())
		{
			int count = 0;

			while (pattern[idx] == '0')
			{
				++idx;
				++count;
			}
			if (count == 1) // 01
			{
				if (one_count == 1)
				{
					answer = false;
					break;
				}
				++idx;
				//prev_num_is_one = false; // ÃÊ±âÈ­
				one_count = 0;
			}

			else if (count >= 2)
			{
				if (one_count == 0)
				{
					answer = false;
					break;
				}
				one_count = 0;
				while (pattern[idx] == '1')
				{
					++idx;
					++one_count;
				}
				if (one_count == 1)
					one_count = 0;
			}

			else if (count==0)
			{
				if (one_count==1)
				{
					answer = false;
					break;
				}
				++idx;
				//prev_num_is_one = true;
				one_count = 1;
			}
			
		}
		if (answer)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}