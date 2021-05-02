#include <iostream>
#include <vector>

using namespace std;

void search(vector<vector<int>>,int,int);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (computers[i][j] == 1) {
                search(computers, i, j);
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> matrix;
    vector<int> mat1;
    vector<int> mat2;
    vector<int> mat3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            if (i == 0) {
                mat1.push_back(a);
            }
            else if (i == 1) {
                mat2.push_back(a);
            }
            else {
                mat3.push_back(a);
            }
        }
        if (i == 0)
            matrix.push_back(mat1);
        else if (i == 1)
            matrix.push_back(mat2);
        else
            matrix.push_back(mat3);
    }
    cout<<solution(3, matrix);
}

void search(vector<vector<int>> mat,int x,int y) {
    if (mat[x][y] == 1) {
        mat[x][y] = 2;
        mat[y][x] = 2;
        search(mat, x + 1, y);
        search(mat, x, y + 1);
        search(mat, x - 1, y);
        search(mat, x, y - 1);
    }
}