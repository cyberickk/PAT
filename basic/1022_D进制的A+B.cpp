#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long a, b;
	string s;
	int d;
	cin >> a >> b >> d;
	long long c = a + b;
	if(c == 0) //c = 0 时字符串为空，要单独输出 
	{
		cout << "0";
		return 0;
	}
	while(c > 0)
	{
		int t;
		t = c % d;
		s += t + '0';
		c /= d;
	}
	for(int i = s.size() - 1; i >= 0; --i)
	cout << s[i];
	
	return 0;
}
