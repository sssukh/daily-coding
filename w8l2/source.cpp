#include<string>
#include<iostream>
#include<vector>
using namespace std;

int snail[1000][1000]{ 0 };

vector<int> solution(int n) {
	vector<int> answer;
	
	int state = 0;//0 - 아래 , 1- 오른쪽 2 - 위
	int total = n * (n + 1) / 2;
	int width = 0;
	int height = 0;
	for (int i = 1; i <= total; i++) {
		if (width>=n||height>=n||snail[width][height] != 0) {
			if (state == 0) {
				height--;
			}
			else if (state == 1) {
				width--;
			}
			else {
				height++;
				width++;
			}
			i--;
			state = (state + 1) % 3;
		}
		else {
			snail[width][height] = i;
		}

		if (state == 0) {//아래
			height++;
		}
		else if (state == 1) {
			width++;
		}
		else {
			width--;
			height--;
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(snail[j][i]);
		}
	}
	
	return answer;
}

int main() {
	int input;
	cin >> input;
	
	for (int c : solution(input)) {
		cout << c<<" ";
	}
}