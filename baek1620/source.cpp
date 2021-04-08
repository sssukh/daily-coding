#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, int> map1;
	vector<string> vec;
	vec.push_back("0");
	for (int i = 0; i < N; i++) {
		string pName;
		cin >> pName;
		map1.insert(make_pair(pName, i + 1));
		vec.push_back(pName);
	}
	
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		if (isdigit(input[0]) == 0) {
			cout << map1[input] << "\n";
		}
		else {
			int tmp = atoi(input.c_str());
			cout << vec[tmp] << "\n";
		}
	}

}