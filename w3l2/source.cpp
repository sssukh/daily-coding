#include<iostream>
#include<vector>
#include<string>
using namespace std;

string solution(int n) {
	string answer = "";
	vector<int> ans;
	while (n > 0) {
		int tmp = n % 3;
		if (tmp == 0) {
			n -= 3;
			ans.push_back(4);
		}
		else {
			ans.push_back(tmp);
			n -= tmp;
		}
		n = n / 3;
	}
	while (ans.size() > 0) {
		int tmp = ans.back();
		if (tmp == 1) {
			answer += "1";
		}
		else if (tmp == 2) {
			answer += "2";
		}
		else if (tmp == 4) {
			answer += "4";
		}
		ans.pop_back();
	}
	return answer;
}
