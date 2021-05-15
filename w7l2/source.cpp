#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> map;
	for (string str : record) {
		string order[3]{"","",""};//order, uid, nickname
		int idx = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				idx++;
				continue;
			}
			order[idx] += str[i];
			
		}
		
		
		if (order[0] == "Enter") {
			map[order[1]] = order[2];
			
		}
		else if (order[0] == "Leave") {
			continue;
		}
		else {
			map[order[1]] = order[2];
		}
	}
	for (string str : record) {
		string order[3]{ "","","" };//order, uid, nickname
		int idx = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				idx++;
				continue;
			}
			order[idx] += str[i];

		}
		if (order[0] == "Enter") {
			answer.push_back(map[order[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (order[0] == "Leave") {
			answer.push_back(map[order[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}
	return answer;
}

int main() {
	vector<string> ex;
	string tmp;
	while (getline(cin,tmp)) {
		ex.push_back(tmp);
	}
	for (string temp : solution(ex)) {
		cout << temp << endl;
	}
}