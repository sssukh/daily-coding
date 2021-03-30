#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> vec;
	string answer;
	int count1;
	int count2;
	while (true) {
		answer = "yes";
		count1 = 0;
		count2 = 0;
		char input[102];
		cin.getline(input,102,'\n');
		if (input[0] == '.') {
			break;
		}
			
		for (int i = 0; i < 100; i++) {
			if (input[i] == '(') {

				vec.push_back(1);
				count1++;
			}
			else if (input[i] == ')') {
				if (count1 <= 0) {
					answer = "no";
					break;
				}
				int tmp = vec.back();
				if (tmp == 2) {
					answer = "no";
					break;
				}
				vec.pop_back();
				count1--;
			}
			else if (input[i] == '[') {

				vec.push_back(2);
				count2++;
			}
			else if (input[i] == ']') {
				if (count2 <= 0) {
					answer = "no";
					break;
				}
				int tmp = vec.back();
				if (tmp == 1) {
					answer = "no";
					break;
				}
				vec.pop_back();
				count2--;
			}
			else if (input[i] == '.')
				break;
		}
		if (count1 != 0 || count2 != 0)
			answer = "no";
		
		cout << answer << endl;
		vec.clear();
	}
}