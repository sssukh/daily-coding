#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	int N, C, midDis, lo, hi,answer=0;
	cin >> N >> C;
	vector<int> houses(N);
	vector<bool> isPlaced(N);
	for (int i = 0; i < N; i++)
	{
		int pos;
		cin >> pos;
		houses[i] = pos;
	}
	sort(houses.begin(), houses.end());
	lo = 0; hi = houses.back();
	while (lo <= hi)
	{
		midDis = (lo + hi) / 2;
		//cout << "midDis : " << midDis << endl;
		// 위치찾기
		/*
		int idx_lo = startIdx, idx_hi = houses.size() - 1, idx_mid,currentDis;
		while (idx_lo<=idx_hi)
		{
			idx_mid = (idx_lo + idx_hi) / 2;
			currentDis = houses[idx_mid] - houses[startIdx];
			if (currentDis == midDis)
			{
				break;
			}
			else if (currentDis < midDis)
			{
				idx_lo = idx_mid + 1;
			}
			else
			{
				idx_hi = idx_mid - 1;
			}
		}
		while (currentDis < midDis)
		{
			currentDis = houses[++idx_mid] - houses[startIdx];
		}
		startIdx = idx_mid;
		*/
		int currentDis = 1e9, count = 1,startIdx=0;
		for (int i = 0; i < N&&count<C; i++)
		{
			if (houses[i] - houses[startIdx] >= midDis)
			{
				currentDis = min(currentDis, houses[i] - houses[startIdx]);
				startIdx = i;
				++count;

				//cout <<"i : "<<i<<"currentDis : " << currentDis << endl;
			}
		}
		if (count < C)
		{
			hi = midDis - 1;
			
		}
		else
		{
			lo = midDis + 1;
			answer = max(answer, currentDis);
		}

	}
	cout << answer;
}