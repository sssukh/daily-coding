#include<iostream>
using namespace std;

class arrStack {
public:
	int n;
	char* st;
	int capacity;
	arrStack(int size) {
		st = new char[size];
		n = 0;
		capacity = size;
	}
	void push(char x) {
		if (n == capacity) {
			return;
		}
		st[n] = x;
		n++;
	}
	bool empty() {
		return n == 0;
	}
	void pop() {
		if (empty()) {
			return;
		}
		st[n-1] = NULL;
		n--;
	}
	char top() {
		if (empty()) {
			return NULL;
		}
		return st[n - 1];
	}
	int size() {
		if (empty()) {
			return 0;
		}
		return n;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		arrStack frontcur(1000001);//cursor와 cursor의 앞부분
		arrStack backcur(1000001);//cursor의 뒷부분

		string input;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '-') {//삭제
				frontcur.pop();
			}
			else if (input[i] == '<') {//커서 앞으로 이동
				if (frontcur.empty()) {
					continue;
				}
				backcur.push(frontcur.top());
				frontcur.pop();
			}
			else if (input[i] == '>') {//커서 뒤로 이동
				if (backcur.empty()) {
					continue;
				}
				frontcur.push(backcur.top());
				backcur.pop();
			}
			else {
				frontcur.push(input[i]);
			}
		}
		for (int i = 0; i < frontcur.size(); i++) {
			cout << frontcur.st[i];
		}
		for (int i = backcur.size() - 1; i >= 0; i--) {
			cout << backcur.st[i];
		}
		cout << "\n";
	}
}