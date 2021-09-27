#include<iostream>
#include <map>
#include <unordered_map>
using namespace std;

int G(int a, int b);

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int A, B, x, y;
		int count = 0;
		cin >> A >> B >> x >> y;
		map<int,int> skill;
		while (count <= abs(A - B))
		{
			int tmp = G(A + count, B + count);
			if (skill[tmp] == 0)
				skill[tmp] = x * count;
			else if (skill[tmp] > x * count)
				skill[tmp] = x * count;
			if (A - count > 0 && B - count>0)
			{
				tmp = G(A - count, B - count);
				if (skill[tmp] == 0)
					skill[tmp] = y * count;
				else if (skill[tmp] > y * count)
					skill[tmp] = y * count;
				
			}
			count++;
		}
		auto iter = --skill.end();
		cout << iter->first << " " << iter->second << "\n";
		
		
		
	}
}
int G(int a, int b)
{
	
	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;
	}
	else if (a > b)
	{
		return G(a - (int)(a / b) * b, b);
	}
	else
	{
		return G(a, b - (int)(b / a) * a);
	}
}