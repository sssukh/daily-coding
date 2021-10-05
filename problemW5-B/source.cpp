#include<iostream>
#include <vector>
using namespace std;

int main()
{
	int N,M;
	cin >> N>>M;
	vector<int> distances(N,0);
	int pos=0;
	int prepos=1;
	int distance = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> pos;
		if (i == N - 1)
			distance = pos;
		distances[i]=(pos - prepos);
		prepos = pos;
	}
	int max_dis = distance / M;

	int mindis = 0;

	while (true)
	{
		int count = 0;
		int current_dis = 0;
		int current_mindis = distance;
		for (int i = 1; i < N; i++)
		{
			current_dis += distances[i];
			if (current_dis >= max_dis)
			{
				count++;
				if (current_dis < current_mindis)
					current_mindis = current_dis;
				current_dis = 0;
			}
			if (count == M - 1)
				break;
		}

		if (count < M - 1)
			max_dis--;
		else
		{
			cout << current_mindis << endl;
			break;
		}

		/*
		int count = 0;
		int current_dis = 0;
		int current_mindis = 1000000000;
		for (int i = 1; i < N; i++)
		{
			current_dis += distances[i];
			if (current_dis > mindis)
			{
				count++;
				if (current_mindis > current_dis)
					current_mindis = current_dis;
				current_dis = 0;
			}
			
			if (count == M - 1)
				break;
		}
		if (count < M - 1)
		{
			cout << mindis << endl;
			break;
		}
		else
		{
			mindis = current_mindis;
		}
		*/


	}
}