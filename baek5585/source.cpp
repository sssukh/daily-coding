#include<iostream>
#include<math.h>
using namespace std;

int solution(int);

int main() {
	int a;
	cin >> a;
	cout << solution(a);
}

int solution(int n) {
	int count = 0;
	n = 1000 - n;
	
	count += floor(n / 500);
	n = n % 500;
	
	count += floor(n / 100);
	n = n % 100;
	
	count += floor(n / 50);
	n = n % 50;

	count += floor(n / 10);
	n = n % 10;
	
	count += floor(n / 5);
	n = n % 5;
	
	count += floor(n / 1);

	return count;
}