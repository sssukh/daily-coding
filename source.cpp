#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	while (N > 0) {
		string answer = "YES";
		int count = 0;
		string VPS;
		cin >> VPS;
		for (int i = 0; i < VPS.size(); i++) {
			if (VPS[i] == '(') {
				count++;
			}
			else {
				count--;
			}
			if (count < 0) {
				answer = "NO";
			}
		}
		if (count != 0) {
			answer = "NO";
		}
		
		cout << answer << endl;
		N--;
	}
}
