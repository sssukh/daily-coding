#include<iostream>
using namespace std;

int solution(int,int,int);

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	cout << solution(N, M, K);
}

int solution(int N, int M, int K) {
	int all=N+M;
	int teams;
	if (2*M <= N) {
		all -= 3 * M;
		teams = M;
		while (true) {
			if (all >= K)
				return teams;
			else {
				all += 3;
				teams -= 1;
			}
		}
	}
	else {
		all -= 1.5 * N;
		teams = N / 2;
		while (true) {
			if (all >= K)
				return teams;
			else {
				all += 3;
				teams -= 1;
			}
		}
	}
}