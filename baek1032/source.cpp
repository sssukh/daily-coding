#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N,length;
	cin >> N;
	vector<string> dir;
	string answer = "";
	for (int i = 0; i < N;i++) {
		string input;
		cin >> input;
		dir.push_back(input);
	}
	length = dir.back().size();
	int idx = -1;
	for (int i = 0; i < length; i++) {//string index
		char tmp = dir[0][i];
		if (tmp == '.') {
			idx = i;
		}
		for (int j = 1; j < N; j++) {//vector index
			if (dir[j][i] != tmp) {
				tmp = '?';
				break;
			}
		}
		answer += tmp;
	}
	if (idx == -1) {
		cout << answer;
		return 0;
	}
	
	bool isSame = true;
	string tmp = dir[0].substr(idx, length -idx);
	for (int i = 1; i < N; i++) {
		if (tmp != dir[i].substr(idx, length -idx)) {
			isSame = false;
		}
	}
	bool isStar = true;
	for (int i = 0; i < idx; i++) {
		if (answer[i] != '?') {
			isStar = false;
		}
	}
	
	if (isSame&&isStar) {
		cout << "*" + tmp;
	}
	else {
		cout << answer;
	}

}