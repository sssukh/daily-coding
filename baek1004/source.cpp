#include<iostream>
#include<math.h>
using namespace std;


int main() {
	int T;
	cin >> T;
	while (T--) {
		int sx, sy, dx, dy;
		cin >> sx >> sy >> dx >> dy;
		int N;
		cin >> N;
		int count = 0;
		while (N--) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			double distance1 = sqrt(pow(sx - cx, 2) + pow(sy - cy, 2));
			double distance2 = sqrt(pow(dx - cx, 2) + pow(dy - cy, 2));
			if (distance1 < r) {
				count++;
			}
			if (distance2 < r) {
				count++;
			}
		}
		cout << count << endl;
	}
}