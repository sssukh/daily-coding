#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	int N;
	cin >> N;
	vector<int> vec;
	while (N--) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	int answer=0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		int count=1;
		int addCnt=0;
		for (int j = i + 1; j < vec.size(); j++) {
			int tmp = vec[j] - vec[j - 1];
			addCnt += tmp;
			if (addCnt >= 5) {
				break;
			}
			count++;
		}
		if (count > answer)
			answer = count;
	}
	answer = 5 - answer;
	cout << answer;
}