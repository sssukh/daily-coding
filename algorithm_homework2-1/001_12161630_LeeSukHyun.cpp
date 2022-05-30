#include<iostream>
#include<string>
#include<vector>
using namespace std;

//fail function �����
vector<int> fail_func(string pattern)
{
	vector<int> ret(pattern.size());
	ret[0] = 0;
	int i = 1, j = 0;
	while (i < pattern.size())
	{
		// ��ġ�ϸ� pattern[0...i]�� �� �� ��ġ�� 
		// prefix�̸鼭 �� �κй��ڿ� pattern[0...j]�� �ٷ� ���� ���� ���ϵ��� 1�� ���Ѵ�.
		if (pattern[i] == pattern[j])
		{
			ret[i] = ++j;
			i++;
		}
		// ���� ������ prefix�� suffix�� ��ġ�ϴ� ���� ��������
		else if (j > 0)
		{
			j = ret[j - 1];
		}
		// suffix�� ��ġ�ϴ� prefix ����
		else
		{
			ret[i] = 0;
			i++;
		}
	}
	return ret;
}

int main()
{
	string book;
	cin >> book;
	string pattern;
	cin >> pattern;
	// fail function
	vector<int> fail = fail_func(pattern);
	// pattern ã�� ��ġ �����ϴ� �迭
	vector<int> start_idx;
	int i = 0, j = 0;
	while (i < book.size())
	{	
		// ��ġ
		if (book[i] == pattern[j])
		{	
			// pattern�� ������ ��ġ
			if (j == pattern.size() - 1)
			{
				start_idx.push_back(i - j);
				// ��ġ�ϴ� �κи�ŭ�� fail�Լ� �� ��������
				j = fail[j];
				// �������� �ű��
				++i;

				cout << pattern.size()-j << " ";
			}
			// pattern�� ������ ��
			else
			{
				++i;
				++j;
			}
		}
		else
		{
			if (j > 0)
			{
				// ������ġ j���� ������ ���� ��ġ�� fail[j-1]��ŭ �ű��
				cout << j - fail[j - 1] << " ";
				j = fail[j - 1];
				
			}
			// ���ۺ��� ��ġ���� �ʾƼ� ��ĭ �ű��
			else
			{
				++i;
				cout << 1 << " ";
			}
		}
	}
	cout << "\n";
	for (int i : start_idx)
		cout << i << " ";
	cout << endl;
}