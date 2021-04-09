#include<iostream>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, x1, y1, x2, y2, r1, r2;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//입력받음
		if (x1 == x2 && y1 == y2) {//두 원의 중심이 같다
			if (r1 == r2) {//두 원이 같다
				cout << -1 << endl;
			}
			else {//두 원의 중심은 같지만 반지름이 다르다.
				cout << 0 << endl;
			}
		}
		else {
			int turretDis = sqrt(pow((x1 - x2),2)  + pow((y1 - y2),2));
			if (turretDis == (r1 + r2)) {
				cout << 1 << endl;
			}
			else if (turretDis > (r1 + r2)) {
				cout << 0 << endl;
			}
			else {
				cout << 2 << endl;
			}
		}
	}
}