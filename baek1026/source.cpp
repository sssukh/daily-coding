#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int , int );

int main() {
	int N;
	cin >> N;
	int answer = 0;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), compare);
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}
	cout << answer;

}

bool compare(int a, int b) {
	return a > b;
}