#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {


	int answer = 0;
	int dlocation = location;
	queue<int> Qpriorities;
	for (int i = 0; i < priorities.size(); i++) {
		Qpriorities.push(priorities[i]);
	}
	sort(priorities.begin(), priorities.end());//우선순위 나열
	
	while (dlocation != -1) {
		
		if (priorities.back() == Qpriorities.front()) {
			Qpriorities.pop();
			priorities.pop_back();
			dlocation -= 1;
			answer++;
		}
		else {
			int tmp = Qpriorities.front();
			Qpriorities.pop();
			Qpriorities.push(tmp);
			dlocation -=1;
			if (dlocation<0) {
				dlocation += Qpriorities.size();
			}
		}
	}



	return answer;
}

bool decrease(int a, int b) {
	return a > b;
}

int main() {

}