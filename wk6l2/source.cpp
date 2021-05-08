#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int solution(string s) {
	int answer = 1001;
	int div = 1;
	while (div < s.size()) {
		string current="";
		string tmp="\0";
		int count=1;
		int result=0;
		int counter = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				tmp = s[i];
			
			}
			else if (i % div == 0) {
				cout << current << " " << tmp << endl;
				counter++;
					if (current == tmp) {
						count++;
						if (counter==2) {
							result -= div;
						}
						
					}
					else {
						if (count != 1) {
							result += floor(log10(count)) + 1;
						}
						result += tmp.size();
						count = 1;
						cout << "res :" << result << endl;
						
					}
			
				
				current = tmp;
				tmp = s[i];
			}
			else {
				tmp += s[i];
			}

		}
		counter++;
		if (current == tmp) {
			count++;
			if (counter == 2) {
				result -= div;
			}
		}
		if (count != 1) {
			result += floor(log10(count)) + 1;
		}
		result += tmp.size();
		cout << current << " " << tmp << endl;
		cout << "res :" << result << endl;
		if (result < answer) {
			answer = result;
			cout << div << endl;
		}
		div++;
	}
	
	return answer;

}
int main() {
	string input;
	cin >> input;
	cout<<solution(input);
}
