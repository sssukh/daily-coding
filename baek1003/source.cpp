#include<iostream>
#include<vector>
using namespace std;

int fibo[41];

void fibonacci(int n) {
    fibo[n] = fibo[n - 1] + fibo[n - 2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 41; i++) {
        fibonacci(i);
    }

    int T;
    cin >> T;
    while (T--) {
       
        int a;
        cin >> a;
        if (a != 0)
            cout << fibo[a-1] << " " << fibo[a] << endl;
        else
            cout << 1 << " " << 0 << endl;
    }
}