#include<iostream>
#include<string>
#include<vector>
using namespace std;

//fail function 만들기
vector<int> fail_func(string pattern)
{
	vector<int> ret(pattern.size());
	ret[0] = 0;
	int i = 1, j = 0;
	while (i < pattern.size())
	{
		// 일치하면 pattern[0...i]의 끝 과 일치한 
		// prefix이면서 진 부분문자열 pattern[0...j]끝 바로 다음 문자 비교하도록 1씩 더한다.
		if (pattern[i] == pattern[j])
		{
			ret[i] = ++j;
			i++;
		}
		// 이전 길이의 prefix와 suffix의 일치하는 길이 가져오기
		else if (j > 0)
		{
			j = ret[j - 1];
		}
		// suffix와 일치하는 prefix 없음
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
	// pattern 찾은 위치 저장하는 배열
	vector<int> start_idx;
	int i = 0, j = 0;
	while (i < book.size())
	{	
		// 일치
		if (book[i] == pattern[j])
		{	
			// pattern의 끝까지 일치
			if (j == pattern.size() - 1)
			{
				start_idx.push_back(i - j);
				// 일치하는 부분만큼의 fail함수 값 가져오기
				j = fail[j];
				// 시작지점 옮기기
				++i;

				cout << pattern.size()-j << " ";
			}
			// pattern의 끝까지 비교
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
				// 현재위치 j에서 다음에 비교할 위치인 fail[j-1]만큼 옮기기
				cout << j - fail[j - 1] << " ";
				j = fail[j - 1];
				
			}
			// 시작부터 일치하지 않아서 한칸 옮기기
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