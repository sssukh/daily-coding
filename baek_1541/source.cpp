#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str,tmp="";
	cin >> str;
	bool is_minus = false;
	int ret = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			tmp+=str[i];
		else
		{
			
			if (is_minus)
				ret -= stoi(tmp);
			else
				ret += stoi(tmp);
			tmp = "";
			if (str[i] == '-')
				is_minus = true;
		}
	}
	if (is_minus)
		ret -= stoi(tmp);
	else
		ret += stoi(tmp);
	cout << ret;
}