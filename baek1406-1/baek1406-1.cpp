#include<iostream>
using namespace std;

class arrayStack {
public:
	int top;
	char* st;
	arrayStack() {
		st = new char[600001];
		top = -1;
	}
	bool empty() {
		return top == -1;
	}
	void pop() {
		if (empty())
			return ;
		st[top]='\0';
		top--;
		
	}
	void push(char x) {
		if (top == 600000)
			return;
		top++;
		st[top] = x;
	}
	char stTop() {
		if (empty())
			return '\0';
		return st[top];
	}
	void showback() {
		for (int i = 0; i <= top; i++) {
			cout << st[i];
		}
	}
	void showfront() {
		for (int i = top; i >= 0; i--) {
			cout << st[i];
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	cin >> word;
	arrayStack front; //커서 오른쪽
	arrayStack back;//커서 왼쪽
	for (int i = 0; i < word.size(); i++) {//초기화
		back.push(word[i]);
	}
	int M;
	cin >> M;
	while (M--) {
		char order;
		cin >> order;
		if (order == 'L') {
			char tmp = back.stTop();
			back.pop();
			if (tmp == '\0')
				continue;
			front.push(tmp);
		}
		else if (order == 'D') {
			char tmp = front.stTop();
			front.pop();
			if (tmp == '\0')
				continue;
			back.push(tmp);
		}
		else if (order == 'B') {
			back.pop();
		}
		else if (order == 'P') {
			char a;
			cin >> a;
			back.push(a);
		}
	}
	back.showback();
	front.showfront();
}