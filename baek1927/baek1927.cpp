#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class minHeap {
public:
	vector<int> v;
	int heapSize;
	minHeap() {
		v.push_back(-1);
		heapSize = 0;
	}
	void swap(int idx1, int idx2) {
		int tmp = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = tmp;
	}
	void upheap(int idx) {
		if (idx == 1)
			return;
		int parIdx = floor(idx / 2);
		if (v[parIdx] > v[idx]) {
			swap(idx, parIdx);
			upheap(parIdx);
		}
	}
	void insert(int x) {
		heapSize++;
		v.push_back(x);
		upheap(heapSize);
	}
	void downheap(int idx) {
		int tmp;
		int lc = 2 * idx;
		int rc = 2 * idx + 1;
		if (lc > heapSize)
			return;
		else if (rc > heapSize)
			rc = heapSize;
		if (v[lc] >= v[rc]) {
			tmp = rc;
		}
		else
			tmp = lc;
		if (v[idx] > v[tmp]) {
			swap(idx, tmp);
			downheap(tmp);
		}
	}
	int pop() {
		if (heapSize == 0)
			return 0;
		int tmp = v[1];
		swap(1, heapSize);
		heapSize--;
		v.pop_back();
		downheap(1);
		return tmp;

	}
	void showheap() {
		for (int i = 0; i <= heapSize; i++) {
			cout << v[i]<<" ";
		}
		cout << endl;
	}
};

int main() {
	int N;
	cin >> N;
	minHeap* heap = new minHeap;
	while (N--) {
		int a;
		cin >> a;
		if (a == 0) {
			cout << heap->pop() << endl;
		}
		else {
			heap->insert(a);
		}
	}
	delete heap;
}