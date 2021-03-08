#include<iostream>
using namespace std;

class set {
public:
	int key;
	int qty;
	set() {
		key = NULL;
		qty = NULL;
	}
	set(int x) {
		key = x;
		qty = 1;
	}
};

class sangkeun {
public:
	set* hash;
	int capacity;
	int hashNum;
	sangkeun(int size) {
		capacity = size;
		hash = new set[size];
		hashNum = 7;
	}
	void add(int x) {
		int tmp = x % hashNum;
		if (tmp < 0)
			tmp += hashNum;
		while (true) {
			if (hash[tmp].key == x) {
				hash[tmp].qty++;
				break;
			}
			else if (hash[tmp].key == NULL) {
				hash[tmp].key = x;
				hash[tmp].qty = 1;
				break;
			}
			else {
				tmp++;
			}
		}
	}
	int count(int x) {
		for (int i = 0; i < capacity; i++) {
			if (hash[i].key == x) {
				return hash[i].qty;
			}
		}
		return 0;
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