#include<iostream>
using namespace std;

class set {
public:
	int x;
	int y;
	set() {
		x = 0;
		y = 0;
	}
	set(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class arrQ {
public:
	int n;
	set* Q;
	int f;
	int r;
	int capacity;
	arrQ(int size) {
		n = 0;
		Q = new set[size];
		f = 0;
		r = -1;
		capacity = size;
	}
	void enqueue(int x,int y) {
		r = (r + 1) % capacity;
		Q[r] = set(x,y);
		n++;
	}
	void dequeue() {
		if (empty())
			return ;
		Q[f].x = 0;
		Q[f].y = 0;
		f = (f + 1) % capacity;
		n--;
	}
	bool empty() {
		return n == 0;
	}
	int topX() {
		return Q[r].x;
	}
	int topY() {
		return Q[r].y;
	}
	bool search(int x, int y) {
		bool check = false;
		for (int i = 0; i < capacity; i++) {
			if (Q[i].x == x&&Q[i].y==y) {
				check = true;
				Q[i].x = 0;
				Q[i].y = 0;
				break;
			}
		}
		return check;
	}
	bool check(int x, int y) {
		int check = 0;
		for (int i = 0; i < capacity; i++) {
			if (Q[i].x == x && Q[i].y == y) {
				check++;
			}
		}
		if (check == 2) {
			return true;
		}
		else {
			return false;
		}
	}
	int tailX() {
		return Q[f].x;
	}
	int tailY() {
		return Q[f].y;
	}
};

class snake {
public:
	arrQ* dummy;
	int direction;
	arrQ* rotation;
	arrQ* apple;
	int capacity;
	int appleAmount;
	int time;
	snake(int size, int apple) {
		
		dummy = new arrQ(100);
		dummy->enqueue(1, 1);
		direction = 0;
		this->apple = new arrQ(apple);
		appleAmount = apple;
		capacity = size;
		time = 0;
		this->rotation = new arrQ(100);
	}
	// 0:right 1: down 2: left 3:up
	void rotate(int time, int rotate) {//rotate 큐 만들어서 time 되면 dequeue하게 만들기
		if (this->time == time) {
			direction = (direction + rotate) % 4;
			if (direction < 0)
				direction += 4;
		}
	}
	void move() {
		cout << "time : " << time << " direction : " << direction << " x : " << dummy->topX() << " y : " << dummy->topY() << endl;
		cout << "length : " << dummy->n << endl;
		cout << "tail  x : " << dummy->tailX() << " y : " << dummy->tailY() << endl;
		time++;
		if (direction == 0) {//move to right
			dummy->enqueue(dummy->topX()+1, dummy->topY());
			
		}
		else if (direction == 1) {
			dummy->enqueue(dummy->topX() , dummy->topY()+1);
			
		}
		else if (direction == 2) {
			dummy->enqueue(dummy->topX() - 1, dummy->topY());
			
		}
		else if (direction == 3) {
			dummy->enqueue(dummy->topX(), dummy->topY()-1);
			
		}
		if (gameend()) {
			return;
		}
		if (!checkApple(dummy->topX(), dummy->topY())) {
			dummy->dequeue();
		}
	}
	void putApple(int x,int y) {
		apple->enqueue(x, y);
	}
	bool checkApple(int x, int y) {
		return apple->search(x, y);
	}
	bool gameend() {
		return dummy->topX() > capacity || dummy->topY() > capacity || dummy->topX() < 1 || dummy->topY() < 1||dummy->check(dummy->topX(), dummy->topY());//몸에 부딫히는거 추가
	}
};

int main() {
	int N;//보드의 크기
	cin >> N;
	int K;//사과의 개수
	cin >> K;
	snake snake(N, K);
	while (K--) {
		int a, b;
		cin >> a >> b;
		snake.putApple(b, a);
	}
	int L;
	cin >> L;
	while (L--) {
		int a;
		char b;
		int c;
		cin >> a >> b;
		if (b == 'D')
			c = 1;
		else
			c = -1;
		snake.rotation->enqueue(a, c);
	}
	while (true) {
		if (snake.gameend())
			break;
		if (snake.rotation->tailX() == snake.time) {
			snake.rotate(snake.rotation->tailX(), snake.rotation->tailY());
			snake.rotation->dequeue();
		}
		snake.move();
	}
	cout << snake.time << endl;
}