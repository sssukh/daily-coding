using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long prices = 0;
    for (int i = 1; i <= count; i++)
    {
        prices += price * i;
    }
    if (prices > money)
        answer = prices - money;
    return answer;
}