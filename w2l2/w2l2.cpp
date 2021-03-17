#include<iostream>
#include<vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> bridge;
	for (int i = 0; i < bridge_length; i++) {//다리 초기화
		bridge.push_back(0);
	}
	int current = 0;
	while (truck_weights.size() > 0) {
		answer++;
		current += truck_weights[0];
		int tmp1 = bridge[0];
		bridge.erase(bridge.begin());
		current -= tmp1;
		if (current <= weight) {
			int tmp = truck_weights[0];
			truck_weights.erase(truck_weights.begin());
			bridge.push_back(tmp);
			
		}
		else{
			current -= truck_weights[0];
			bridge.push_back(0);
			
		}
		for (int a : bridge) {
			cout << a;
		}
		cout << endl;
	}
	answer += bridge_length;
	return answer;
}

int main() {
	vector<int> ex = { 7,4,5,6 };
	solution(2, 10, ex);
}