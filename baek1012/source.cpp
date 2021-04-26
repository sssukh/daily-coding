#include<iostream>
using namespace std;

#define MAX 51

void check( int, int);

int map[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int M, N, K;
		int count = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				map[i][j] = 0;
			}
		}

		while (K--) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}
	
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					check( i, j);
					count++;
				}
			}
		}
		cout << count << "\n";
		
		
	}
}
void check(int m, int n) {
	if (map[m][n] == 1) {
		map[m][n] = 2;
		check( m + 1, n);
		check( m, n + 1);
		check(m - 1, n);
		check(m, n - 1);
	}
	
}