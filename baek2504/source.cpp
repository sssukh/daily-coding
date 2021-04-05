#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int check1 = 0;
	int check2 = 0;
	string input;
	cin >> input;
	vector<int> vec;
	int answer = 0;
	for (int i = 0; i < input.size(); i++) {//괄호열 맞는지 check
		if (input[i] == '(') {
			check1++;
			vec.push_back(1);
		}
		else if (input[i] == '[') {
			check2++;
			vec.push_back(2);
		}
		else if (input[i] == ')') {
			check1--;
			if (vec.empty()) {//비었는데 pop
				cout << 0 << endl;
				return 0;
			}
			int tmp = vec.back();
			if (tmp != 1) {
				cout << 0 << endl;
				return 0;
			}
			vec.pop_back();
		}
		else if (input[i] == ']') {
			check2--;
			if (vec.empty()) {//비었는데 pop
				cout << 0 << endl;
				return 0;
			}
			int tmp = vec.back();
			if (tmp != 2) {
				cout << 0 << endl;
				return 0;
			}
			vec.pop_back();
		}
		if (check1 < 0 || check2 < 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (check1 != 0 || check2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			vec.push_back(-1);
		}
		else if (input[i] == '[') {
			vec.push_back(-2);
		}
		else if (input[i] == ')') {
			if (input[i - 1] == '(') {
				vec.pop_back();
				vec.push_back(2);
			}
			else {
				int tmp = 0;
				while (vec.back() != -1) {
					tmp += vec.back();
					vec.pop_back();
				}
				vec.pop_back();
				vec.push_back(tmp * 2);
			}
		}
		else if (input[i] == ']') {
			if (input[i - 1] == '[') {
				vec.pop_back();
				vec.push_back(3);
			}
			else {
				int tmp = 0;
				while (vec.back() != -2) {
					tmp += vec.back();
					vec.pop_back();
				}
				vec.pop_back();
				vec.push_back(tmp * 3);
			}
		}
	}
	for (int i : vec) {
		answer += i;
	}
	cout << answer;

}
