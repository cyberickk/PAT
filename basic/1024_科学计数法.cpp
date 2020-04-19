#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, s1, s2;
	cin >> s;
	char c1 = s[0];
	if(c1 == '-') cout << "-";
	int i = 1, cnt = 0;
	for(i = 1; s[i] != 'E'; i++)
	{
		if(s[i] == '.') continue;
		s1 += s[i];
		cnt++;
	}		
	char c2 = s[++i];
	for(++i; i < s.size(); ++i)
		s2 += s[i];
	int d = stoi(s2);
	if(c2 == '-')
	{
		cout << "0.";
		for(int j = 1; j < d; ++j)
			cout << "0";
	}
	for(int j = 0; j < s1.size(); ++j)
	{
	 	if(s1[j] == '.') continue;
		cout << s1[j];
	}
	if(c2 == '+')
	{
		for(int j = 0; j <= d - cnt; ++j)
			cout << "0";
	}
	return 0;
}
