#include<iostream>
#include<deque>
using namespace std;



int main() {
	int N, M;
	cin >> N >> M;
	deque<int> deq;
	for (int i = 0; i < N; i++) {
		deq.push_back(i + 1);
	}//초기화
	int count = 0;
	while (M--) {
		int a;
		cin >> a;
		if (deq.front() == a) {
			deq.pop_front();
			continue;
		}
		int idx=0;
		for (int i = 0; i < deq.size(); i++) {
			if (deq[i] == a) {
				idx = i;
				break;
			}
		}
		
		if (idx  > (deq.size() / 2)) {//3번 연산
			
			while (deq.front() != a) {
				int tmp = deq.back();
				deq.pop_back();
				deq.push_front(tmp);
				count++;
				
			}
			deq.pop_front();

		}
		else {
			
			while (deq.front() != a) {
				int tmp = deq.front();
				deq.pop_front();
				deq.push_back(tmp);
				count++;
				
			}
			deq.pop_front();
		}


		

	}
	cout << count;
}