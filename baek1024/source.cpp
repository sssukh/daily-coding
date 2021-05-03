#include<iostream>
#include<math.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;
	int length=L-1;
	int nums;
	bool check = false;
	while (length<=99) {
		
		length++;
		
		nums = floor(N / length);
		
		
		int result=0;
		while (N>result) {
			result = length*(2*nums-length+1) / 2;
			
			if (result == N) {
				check = true;
				break;
			}
			else
				nums++;
		}
		if (nums < length) {
			check = false;
			continue;
		}
		if (check)
			break;
		
	}
	if (check) {
		for (int i = nums - length + 1; i <= nums; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << -1;
	}
}