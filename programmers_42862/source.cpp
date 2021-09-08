#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 2, 1);
    for (int i = 0; i < reserve.size(); i++) student[reserve[i]]++;
    for (int i = 0; i < lost.size(); i++) student[lost[i]]--;
    for (int i = 1; i <= n; i++) {
        if (student[i - 1] == 0 && student[i] == 2) student[i - 1] = student[i] = 1;
        else if (student[i] == 2 && student[i + 1] == 0) student[i] = student[i + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (student[i] > 0) answer++;
    return answer;
}