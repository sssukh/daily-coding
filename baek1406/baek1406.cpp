#include<iostream>
using namespace std;

class editor {
public:
	int cursor;
	char* words;
	int length;
	editor(string L) {
		words = new char[600000];
		cursor = L.size();
		length = L.size();
		for (int i = 0; i < L.size(); i++) {
			words[i] = L[i];
		}
	}
	void left() {
		if (cursor == 0)
			return;
		cursor--;
	}
	void right() {
		if (cursor == length)
			return;
		cursor++;
	}
	void remove() {
		if (cursor == 0)
			return;
		for (int i = cursor; i < length; i++) {
			words[i - 1] = words[i];
		}
		length--;
		left();
	}
	void insert(char x) {
		for (int i = length; i > cursor; i--) {
			words[i] = words[i - 1];
		}
		length++;
		words[cursor] = x;
		right();
	}
	void show() {
		for (int i = 0; i < length; i++) {
			cout << words[i];
		}
		cout << endl;
	}
};

int main() {
	string N;
	cin >> N;
	editor* edit = new editor(N);
	int M;
	cin >> M;
	while (M--) {
		char order;
		cin >> order;
		if (order == 'P') {
			char a;
			cin >> a;
			edit->insert(a);
		}
		else if (order == 'L') {
			edit->left();
		}
		else if (order == 'D') {
			edit->right();
		}
		else if (order == 'B') {
			edit->remove();
		}
	}
	edit->show();
	delete edit;
}