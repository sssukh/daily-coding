#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first + a.second < b.first + b.second;
}

int main()
{

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<pair<int,int>> A;
		while (N--)
		{
			int a, b;
			cin >> a >> b;
			A.push_back(make_pair(a, b));
		}
		sort(A.begin(), A.end(),cmp);

		int answer = 0;
		while (!A.empty())
		{
			answer += A.back().first;
			A.pop_back();
			if(A.empty())
				break;
			answer -= A.back().second;
			A.pop_back();
		}

		cout << answer << endl;
		
		
		
	}
	
}