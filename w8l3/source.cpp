#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>

using namespace std;

bool compare(vector<int> a,  vector<int> b) {
	return a[1] > b[1];
}

bool compare1(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	sort(jobs.begin(), jobs.end(), compare1);//jobs 를 요청받은 시간순서대로 나열
	int current_time = 0;
	int idx = 0;
	vector<vector<int>> sche_Q;//scheduling 해줄 Q 생성
	int qty = 0;
	while (qty<jobs.size()) {
		
		while (idx < jobs.size()&&jobs[idx][0] <= current_time) {//요청받아서 scheduling queue에 넣기
			sche_Q.push_back(jobs[idx]);
			idx++;
		}
		if (!sche_Q.empty()) {
			sort(sche_Q.begin(), sche_Q.end(), compare);//sche_Q를 소요되는 시간 내림차순으로 나열
			
			current_time += sche_Q.back()[1];
			answer += current_time;
			answer -= sche_Q.back()[0];
			sche_Q.pop_back();
			qty++;
		}
		else {
			current_time++;
		}
	}
	return floor(answer/jobs.size());
}

int main() {
	vector<vector<int>> jobs;
	jobs.push_back({ 0,3 });
	jobs.push_back({ 1,9 });
	jobs.push_back({ 2,6 });
	cout << solution(jobs);
}