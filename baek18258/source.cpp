#include<iostream>
using namespace std;

class arrQ {
public:
	int n;//Q에 들어있는 요소의 개수
	int f;//front index
	int r;//rear index
	int capacity;
	int* Q;
	arrQ(int size) {
		n = 0;
		f = 0;
		r = -1;
		capacity = size;
		Q = new int[size];
	}
	bool empty() {
		return n == 0;
	}
	int size() {
		return n;
	}
	void push(int x) {
		r = (r + 1) % capacity;
		Q[r] = x;
		n++;
	}
	int pop() {
		if (empty())
			return -1;
		int tmp = Q[f];
		f = (f + 1) % capacity;
		n--;
		return tmp;
	}
	int front() {
		if (empty())
			return -1;
			return Q[f];
	}
	int back() {
		if (empty())
			return -1;
			return Q[r];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	arrQ q(2000000);
	while (N--) {
		string order;
		cin >> order;
		if (order == "push") {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (order == "back") {
			cout << q.back() << endl;
		}
		else if (order == "size") {
			cout << q.size() << endl;
		}
		else if (order == "empty") {
			cout << q.empty() << endl;
		}
		else if (order == "pop") {
			cout << q.pop() << endl;
		}
		else if (order == "front") {
			cout << q.front() << endl;
		}
	}
}