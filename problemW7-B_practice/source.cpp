#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct vector2
{
	int x, y;
	//int distance;
}vector2;

struct cmp
{
	bool operator()(vector2 a, vector2 b)
	{
		int disA = a.x * a.x + a.y * a.y;
		int disB = b.x * b.x + b.y * b.y;

		if (disA == disB)
		{
			if (a.x == b.x)
				return a.y < b.y;
			else
				return a.x < b.x;
		}
		return disA < disB;
	}
};

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;
		priority_queue<vector2, vector<vector2>, cmp> hamburgers;
		for (int i = 0; i < M; i++)
		{
			int inputx, inputy;
			cin >> inputx >> inputy;
			int dis = inputx * inputx + inputy * inputy;
			vector2 tmp{ inputx,inputy };
			hamburgers.push(tmp);
		}
		for (int i = 0; i < N; i++)
		{
			int inputx, inputy;
			cin >> inputx >> inputy;
			int dis = inputx * inputx + inputy * inputy;
			vector2 tmp{ inputx,inputy};
			hamburgers.push(tmp);
			while (hamburgers.size() > K)
				hamburgers.pop();
			cout << hamburgers.top().x << " " << hamburgers.top().y << endl;
		}
	}
}