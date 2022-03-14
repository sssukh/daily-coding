#include<iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> houses(N, vector<int>(3,0));
	for (int i = 0; i < N; i++)
	{
		int red, green, blue;
		cin >> red >> green >> blue;
		houses[i][0] = red;
		houses[i][1] = green;
		houses[i][2] = blue;
	}
	for (int i = 1; i < N; i++)
	{
		houses[i][0] += min(houses[i - 1][1], houses[i - 1][2]);
		houses[i][1] += min(houses[i - 1][0], houses[i - 1][2]);
		houses[i][2] += min(houses[i - 1][0], houses[i - 1][1]);
	}
	cout << min(houses.back()[0], min(houses.back()[1], houses.back()[2])) << endl;
}