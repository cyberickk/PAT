#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//int flag[21] = {0};

int add(int a, int b, int j, int& carry)
{
	if(j == 0) j = 10;
	int c = a + b + carry;
	if(c >= j)
	{
		carry = 1;
		return c - j;
	}
	else
	{
		carry = 0;
		return c;
	}
	
}

int main()
{
	string s, s1, s2, r;
	cin >> s >> s1 >> s2;
	reverse(s.begin(), s.end());
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	s1.append(s.size() - s1.size(), '0');
	s2.append(s.size() - s2.size(), '0');
	int si = s1.size(), carry = 0;
	for(int i = 0; i < si; ++i)
	{
		int tmp;
		tmp = add(s1[i] - '0', s2[i] - '0', s[i] - '0', carry);
		r += tmp + '0';
	}
	if(carry) r += '1';
	reverse(r.begin(), r.end());
	int flag = 0;
	for(int i = 0; i < r.size(); ++i)
	{
		if(r[i] != '0' || flag)
		{
			flag = 1;
			cout << r[i];
		}
	}
	if(flag == 0) cout << "0";	
	
	return 0;
}
