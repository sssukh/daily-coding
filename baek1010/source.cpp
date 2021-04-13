#include<iostream>

using namespace std;

int combination(int a, int b);

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int b, a;
		cin >> b >> a;
		int tmp = 1;
		if (b == a) {
			cout << 1 << endl;
		}
		else {
			for (int i = 1; i <= b; i++) {
				tmp =tmp* a / i;
				a--;
			}
			cout << tmp << endl;
		}
	}
}

