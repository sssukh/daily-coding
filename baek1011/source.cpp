#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		double x, y;
		cin >> x >> y;
		double halflength = (y - x)/2;
		int tmp = 1;
		int count = 0;
		
		while (halflength>0) {
			halflength -= tmp;
			tmp++;
			count++;
		}
			tmp--;
			halflength += tmp;
			if (2 * halflength - tmp > 0) {
				cout << count * 2 << "\n";
			}
			else {
				cout << count * 2 - 1 << "\n";
			}
	}
}