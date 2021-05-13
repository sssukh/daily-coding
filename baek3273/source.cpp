#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> array;
	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		array.push_back(a);
	}
	int x;
	cin >> x;
	sort(array.begin(), array.end());
	int left = 0;
	int right = n - 1;
	int count=0;
	while (left < right) {
		if (array[left] + array[right] == x){
			count++;
			left++;
			right--;
		}
		else if (array[left] + array[right] < x) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << count;
}