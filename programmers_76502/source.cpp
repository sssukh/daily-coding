#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> st;
    int sSize = s.size();
    for (int i = 0; i < sSize; i++)
    {
        int j;
        for (j=i;j<sSize+i;j++)
        {
            if (s[j % sSize] == '(')
                st.push_back(1);
            else if (s[j % sSize] == '[')
                st.push_back(2);
            else if (s[j % sSize] == '{')
                st.push_back(3);
            else if (s[j % sSize] == ')')
            {
                if (st.empty())
                    break;
                else if (st.back() == 1)
                    st.pop_back();
                else
                    break;
            }
            else if (s[j % sSize] == ']')
            {
                if (st.empty())
                    break;
                else if (st.back() == 2)
                    st.pop_back();
                else
                    break;
            }
            else if (s[j % sSize] == '}')
            {
                if (st.empty())
                    break;
                else if (st.back() == 3)
                    st.pop_back();
                else
                    break;
            }
        }
        if (st.empty() && j == sSize + i)
            answer++;

        cout << i << " " << answer << endl;
        st.clear();
    }

    return answer;
}

int main()
{
    solution("[]");
}