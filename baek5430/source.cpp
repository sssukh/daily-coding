#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	string func;
	string array;
	deque<int> deq;

	cin >> T;
	while (T--) {
		bool check = true;//false이면 error
		int n;
		bool rev=false;//false이면 정방향, true이면 역방향
		cin >> func;
		cin >> n;
		cin >> array;
		string tmp="";
		for (int i = 1; i < array.size(); i++) {
			if (array[i] == ',' || array[i] == ']') {
				deq.push_back((atoi(tmp.c_str())));
				tmp = "";
			}
			else {
				tmp += array[i];
			}
		}
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') {
				rev = !rev;
			}
			else if (func[i] == 'D') {
				if (n==0) {
					check = false;
					break;
				}
				else {
					if (rev) {
						deq.pop_back();
					}
					else {
						deq.pop_front();
					}
					n--;
				}
			}
		}
		if (check) {
			if (n > 0) {
				cout << '[';
				if (!rev) {
					for (int i = 0; i < n - 1; i++) {
						cout << deq[i] << ',';
					}
					cout << deq.back() << ']' << endl;
				}
				else {
					for (int i = n-1; i >0; i--) {
						cout << deq[i] << ',';
					}
					cout << deq.front() << ']' << endl;
				}

			}
			else
				cout << "[]" << endl;
		}
		else {
			cout << "error" << endl;
		}
		deq.clear();
	}
	
	
}