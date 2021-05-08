#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int solution(string s) {
	int answer = 1001;
	vector<string> store;
	int div = 1;
	while (div < s.size()) {
		int count;
		string tmp;
		int result=0;
		for (int i = 0; i < s.size(); i++) {
			if (i % div == 0) {
				if (i > 0) {
					store.push_back(tmp);
				}
				tmp = s[i];
			}
			else {
				tmp += s[i];
			}
		
		}
		store.push_back(tmp);



		for (int i = 0; i < store.size()-1; i++) {
			count = 1;
			
			while (store[i] == store[i + 1]) {
				count++;
				
				i++;
				if (i == store.size() - 1) {
					break;
				}

			}
			if (count != 1) {
				result += int(log10(count)) + 1;
			}
			result += div;
			
		}
		if (store.back() != store[store.size() - 2]) {
			result += store.back().size();
		}
		
		if (answer > result) {
			answer = result;
		}
		div++;
		store.clear();
	}
	if (answer == 1001)
		answer = 1;
	return answer;
}
int main() {
	string input;
	cin >> input;
	cout<<solution(input);
}
