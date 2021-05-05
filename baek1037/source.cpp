#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> nums;
	int answer;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
	answer = nums.front() * nums.back();
	cout << answer;

}