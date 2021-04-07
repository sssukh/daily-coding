#include<iostream>
#include<vector>
using namespace std;

class set {
public:
	int index;
	int value;
	set() {
		index = NULL;
		value = NULL;
	}
	set(int idx, int val) {
		index = idx;
		value = val;
	}

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	vector<set> simul;
	vector<int> tops;
	
	int N;
	cin >> N;
	int count = N;
	while (count--) {
		int a;
		cin >> a;
		tops.push_back(a);
	}
	
	for (int i = 0; i < N; i++) {
		int tmp = tops[i];
		while (!simul.empty() && simul.back().value < tmp) {
			simul.pop_back();
		}
		if (simul.empty()) {
			cout << 0 << " ";
		}
		else {
			cout << simul.back().index << " ";
		}
		simul.push_back(set(i + 1, tmp));
	}
	
}

