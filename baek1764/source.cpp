#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;



int main() {
	
	vector<string> listen;
	
	vector<string> answer;
	int count=0;
	int N, M;
	cin >> N >> M;
	
	
	while (N--) {
		string a;
		cin >> a;
		listen.push_back(a);
		
	}
	sort(listen.begin(), listen.end());
	while (M--) {
		string a;
		cin >> a;
		if (binary_search(listen.begin(), listen.end(),a)) {
			answer.push_back(a);
		}
	}
	sort(answer.begin(), answer.end());



	
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}