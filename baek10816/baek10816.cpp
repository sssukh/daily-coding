#include<iostream>
#include<vector>
using namespace std;

class set {
public:
	int key;
	int qty;
	set(int x) {
		key = x;
		qty = 1;
	}
};

class sangkeun {
public:
	vector<int> cards;
	int capacity;
	sangkeun(int size) {
		capacity = size;
	}
	void add(int x) {
		cards.push_back(x);

	}
	int count(int x) {
		int tmp = 0;
		for (int i = 0; i < capacity; i++) {
			if (cards[i] == x) {
				tmp++;
			}
		}
		return tmp;
	}
};

int main() {
	int N;
	cin >> N;
	sangkeun* me = new sangkeun(N);
	while (N--) {
		int a;
		cin >> a;
		me->add(a);
	}
	int M;
	cin >> M;
	while (M--) {
		int a;
		cin >> a;
		cout << me->count(a) << "\n";
	}
	delete me;
}