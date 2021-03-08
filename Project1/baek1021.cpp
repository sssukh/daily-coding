#include<iostream>
using namespace std;

class Deque {
public:
	int n;
	int f;
	int r;
	int capacity;
	int* Q;
	Deque(int size) {
		n = 0;
		f = 0;
		r = -1;
		capacity = size;
		Q = new int[size];
		for (int i = 0; i < capacity; i++) {
			push_back(i+1);
		}
	}
	void push_back(int x) {
		r = (r + 1) % capacity;
		Q[r] = x;
		n++;
	}
	void push_front(int x) {
		f = (f - 1) % capacity;
		if (f < 0)
			f += capacity;
		Q[f] = x;
		n++;
	}
	int pop_back() {
		int tmp = Q[r];
		r = (r - 1) % capacity;
		if (r < 0)
			r += capacity;
		n--;
		return tmp;
	}
	int pop_front() {
		int tmp = Q[f];
		f = (f + 1) % capacity;
		n--;
		return tmp;
	}
	int front() {
		return Q[f];
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	Deque* Q = new Deque(N);
	int count = 0;
	while (M--) {
		int a;
		cin >> a;
		while (a!=Q->front()) {
			if (a > Q->front()) {
				if (Q->n / 2 < a - Q->front()) {
					int tmp = Q->pop_back();
					Q->push_front(tmp);
					count++;
				}
				else {
				int tmp = Q->pop_front();
				Q->push_back(tmp);
				count++;
			}
			}
			else if (a < Q->front()) {
				if (Q->n / 2 < Q->front() - a) {
					int tmp = Q->pop_front();
					Q->push_back(tmp);
					count++;
				}
				else {
					int tmp = Q->pop_back();
					Q->push_front(tmp);
					count++;
				}
			}


		}
		Q->pop_front();
	}
	cout << count << endl;
	delete Q;
	
}